#include <stdio.h>

float dgr_alc(float target_hour) {
    float punch_alcool = 20.0;
    // float punch_volume = 4.0;
    float start_hour = 19.5;
    
    if (target_hour < start_hour)
    {
      target_hour += 24;
    }
    
    float nb_hours = target_hour - start_hour;
    int tmp = nb_hours;
    for (int i = 0; i < tmp; i++)
    {
      punch_alcool *= 0.75;
    }

    return punch_alcool;


}

int main() {
  
  float target_hour;
  scanf("%f", &target_hour);

  printf("%.2f\n", dgr_alc(target_hour));
  
  return 0;
}