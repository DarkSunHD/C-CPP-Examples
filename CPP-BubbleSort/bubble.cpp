#include <iostream>
#include <thread>
#include <ctime>
#include <vector>
#include <chrono>


void bubblesort(std::vector<int>& array)
{
        bool swapp = true;
        while(swapp){
                swapp = false;
                for (size_t i = 0; i < array.size()-1; i++) {
                        if (array[i] > array[i+1] ){
                                array[i] += array[i+1];
                                array[i+1] = array[i] - array[i+1];
                                array[i] -= array[i+1];
                                swapp = true;
                        }
                }
        }
        
}


int* create_random_array(int size, int array[]){

        int limit = size * 1;

        
        std::srand(std::time(nullptr));

        
        for(int i = 0; i < size; i++){
                int random_value = std::rand() % limit + 1;
                array[i] = random_value;
        }

        return array;
}

double diffclock(clock_t clock1, clock_t clock2 ) {

        double diffticks = clock1 - clock2;
        double diffms    = diffticks / (double) CLOCKS_PER_SEC;
        return diffms;
}

double diffclockms(clock_t clock1, clock_t clock2 ) {

        double diffticks = clock1 - clock2;
        double diffms    = diffticks / (double) (CLOCKS_PER_SEC/1000);
        return diffms;
}


int main(int argc, char *argv[])
{

        int t = 1;
        int s = 10000;
        bool b_output = false;
        std::string usage = "Usage: -t Threads (std: 1), -s Size of Array (std: 10000), -o Ouput (std: 0 = false)";
        
        if(argc != 1){
                for(int i = 1; i < argc; i = i + 2){
                        if(std::string(argv[i]) == "-t"){
                                if(argc > i + 1){
                                        int y = std::atoi(argv[i+1]);
                                        if(y > 0){
                                                t = y;
                                        }else{
                                                std::cout << usage << std::endl;
                                                return 1;
                                        }
                                }else{
                                        std::cout << usage << std::endl;
                                        return 1;
                                }
                        }else if(std::string(argv[i]) == "-s"){
                                if(argc > i + 1){
                                        int y = std::atoi(argv[i+1]);
                                        if(y > 0){
                                                s = y;
                                        }else{
                                                 std::cout << usage << std::endl;
                                                 return 1;
                                        }
                                }else{
                                        std::cout << usage << std::endl;
                                        return 1;
                                }
                        }else if(std::string(argv[i]) == "-o"){
                                 if(argc > i + 1){
                                         if(std::string(argv[i+1]) == "0"){
                                                 b_output = false;
                                         }else if (std::string(argv[i+1]) == "1"){
                                                 b_output = true;
                                         }else{
                                                  std::cout << usage << std::endl;
                                                  return 1;
                                         }
                                }else{
                                        std::cout << usage << std::endl;
                                        return 1;
                                }
                        }else{
                                std::cout << usage << std::endl;
                                return 1;
                        }
                }
        }


        std::cout << "START RANDOM" << std::endl;
        
        int buff_array [s];
        int *main_array = create_random_array(s, buff_array );

        std::vector<std::vector<int> > thread_array;
        thread_array.resize(t);

        std::cout << "START (prepare threads)" << std::endl;
        
        clock_t start = clock();
        const auto t_start = std::chrono::high_resolution_clock::now();


        int splitint = (int) (s / t);
        int isplit = splitint;
        int privsplit = 0;
        
        for(int i = 0; i < t; i++){
                int count = 0;
                for(int x = 0; x <= s; x++){
                        if(main_array[x] <= isplit && main_array[x] > privsplit){
                                thread_array[i].resize(count + 1);
                                thread_array[i][count] = main_array[x];
                                count++;
                        }
                }
                if(i + 2 == t){
                        privsplit = isplit;
                        isplit = s;
                }else{
                        privsplit = isplit;
                        isplit = isplit + splitint;
                }
        }

        std::thread thread_list[t];

        const auto t_start_sort = std::chrono::high_resolution_clock::now();
        
        std::cout << "START SORT" << std::endl;
        clock_t start_sort = clock();
        
        for(int i = 0; i < t; i++){
                thread_list[i] = std::thread(bubblesort,std::ref(thread_array[i]));
        }
        
        for(int i = 0; i < t; i++){
                thread_list[i].join();
        }

        const auto t_stop = std::chrono::high_resolution_clock::now();

        if(b_output){
                for(int i = 0; i < thread_array.size(); i++){
                        for(int x = 0; x < thread_array[i].size(); x++){
                                std::cout << thread_array[i][x] << std::endl;
                        }
                }
                std::cout << " " << std::endl;
                std::cout << " " << std::endl;
                std::cout << " " << std::endl;
        }
        
        clock_t stop = clock();
        
        

        std::cout << "FIN" << std::endl;
        std::cout << " " << std::endl;
        std::cout << "Line Thread Time (with thread create): " << diffclockms(stop, start) << "ms" << std::endl;
        std::cout << "Line Thread Time (without thread create): " << diffclockms(stop, start_sort) << "ms" << std::endl;

        auto time_all = t_stop - t_start;
        auto time_sort = t_stop - t_start_sort;
        auto time_thread = t_start_sort - t_start;

        std::cout << " " << std::endl;
        std::cout << "Real elapsed time:" << std::endl;
        std::cout << "Complete: " << std::chrono::duration<double, std::milli>(time_all).count() << "ms" << std::endl;
        std::cout << "Thread: " << std::chrono::duration<double, std::milli>(time_thread).count() << "ms" << std::endl;
        std::cout << "Sort: " << std::chrono::duration<double, std::milli>(time_sort).count() << "ms" << std::endl;

        std::cout << " " << std::endl;
        std::cout << "Threads: " << t << std::endl;
        std::cout << "Array size: " << s << std::endl;
        std::cout << "Thread array size: " << splitint << std::endl;
        return 0;
}
