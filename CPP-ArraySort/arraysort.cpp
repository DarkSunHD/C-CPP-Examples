#include <iostream>
#include <ctime>
#include <chrono>




int main(int argc, char *argv[])
{

        long s = 1000000;
        bool b_output = false;
        std::string usage = "Usage: -s Size of Array (std: 1000000), -o Ouput (std: 0 = false)";
        
        if(argc != 1){
                for(int i = 1; i < argc; i = i + 2){
                        if(std::string(argv[i]) == "-s"){
                                if(argc > i + 1){
                                        long y = std::atoi(argv[i+1]);
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


        int *main_array = new int[s];
        int limit = 1000000;

        
        std::srand(std::time(nullptr));

        
        for(int i = 0; i < s; i++){
                int random_value = std::rand() % limit + 1;
                main_array[i] = random_value;
        }
        
        int sort_array [limit + 1];


        for(long i = 0; i < (limit + 1); i++){
                sort_array[i] = 0;
        }
        
        
        std::cout << "Start Sort" << std::endl;

        const auto t_start = std::chrono::high_resolution_clock::now();        

        for(long i = 0; i < s; i++){
                sort_array[main_array[i]] = sort_array[main_array[i]] + 1;
        }

        const auto t_stop = std::chrono::high_resolution_clock::now();


        auto time_all = t_stop - t_start;
        
        
        if(b_output){
                
                for(long i = 0; i < (limit + 1); i++){
                        for(int j = 0; j < sort_array[i]; j++){
                                std::cout << i << std::endl;
                        }
                }
        }
        
        
        std::cout << "FIN" << std::endl;

        std::cout << "Time elapsed: " << std::chrono::duration<double, std::milli>(time_all).count() << "ms" << std::endl;
}
