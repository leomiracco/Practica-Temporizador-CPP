#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>

void countdown(int hours, int minutes, int seconds, int milliseconds){
  int total_milliseconds = (hours * 3600000) + (minutes * 60000) + (1000 * seconds) + milliseconds;
  std::chrono::system_clock::time_point start_time = std::chrono::system_clock::now();
  //auto start_time = std::chrono::system_clock::now();
  std::chrono::time_point<std::chrono::system_clock> FUTURE_TIME = start_time + std::chrono::milliseconds(total_milliseconds);
  //auto FUTURE_TIME = start_time + std::chrono::milliseconds(total_milliseconds);

  while (true){
    std::chrono::system_clock::time_point start_time = std::chrono::system_clock::now();
    //start_time = std::chrono::system_clock::now();
    std::chrono::milliseconds elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(FUTURE_TIME - start_time);
    //auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(FUTURE_TIME - start_time).count();
    
    // if(elapsed_time <= 0){
    //   break;
    // }

    if(elapsed_time.count() <= 0){
        break;
    }

    // int remaining_milliseconds = elapsed_time % 1000;
    // int remaining_seconds = (elapsed_time / 1000) % 60;
    // int remaining_minutes = (elapsed_time / 60000) % 60;
    // int remaining_hours = (elapsed_time / 3600000);

    int remaining_milliseconds = elapsed_time.count() % 1000;
    int remaining_seconds = (elapsed_time.count() / 1000) % 60;
    int remaining_minutes = (elapsed_time.count() / 60000) % 60;
    int remaining_hours = (elapsed_time.count() / 3600000);

    //system("CLS");
    // "\r" elimina la línea, es decir, elimina y dibuja
    // "%02d" significa que el valor de la variable van a
    // ser 2 dígital en el sistema de numeración decimal
    // y en el caso que la variable no contenga 2 dígitos
    // se rellenará a la izquierda con un cero.
    // "%02b\n" esto es lo mismo pero muestra el sistema de
    // numeración binario.
    printf("\r%02d:%02d:%02d.%03d", remaining_hours, remaining_minutes, remaining_seconds, remaining_milliseconds);
    //printf("%02d:%02d:%02d.%03d\n", remaining_hours, remaining_minutes, remaining_seconds, remaining_milliseconds);
  }
  //system("CLS");
  printf("\r00:00:00.000");
  //printf("00:00:00.000");
  Beep(440, 1000);
  
  // With this line, we expect the user to press
  // the Enter key (only works with the Enter key) and it is a
  // cross-platform line of code --> "std::cin.get();".
  //std::cin.get();

  std::cout << "\n\n";
  system("pause");
}

int main(int argc, char const *argv[]){
  countdown(0, 0, 10, 0);
  return 0;
}