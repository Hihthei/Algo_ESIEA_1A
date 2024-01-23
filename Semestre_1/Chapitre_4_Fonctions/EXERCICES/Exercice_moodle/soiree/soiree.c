#include<stdio.h>
#include<math.h>

float dgr_alc(float alc, float dil, float dgr_alc_ini) {
  // Calculer la concentration d'alcool initiale
  float c_alc_ini = dgr_alc_ini / 100.0;

  // Calculer la quantité totale de la solution finale
  float v_total = alc + dil;

  // Calculer la quantité d'alcool dans la solution finale
  float v_alc_fnl = c_alc_ini * alc;

  // Calculer le pourcentage d'alcool dans la solution finale
  float dgr_alc_final = v_alc_fnl / v_total * 100.0;

  // Retourner le pourcentage d'alcool final
  return dgr_alc_final;
}

float dilution(float h)
{
  int v_consomme = (h - 19.5);

  float dgr_act = 40, v_alc_act = 2, v_dil_act = 2;
  for (int i = 0; i < v_consomme; i++)
  {
    v_alc_act -= 0.5;
    v_dil_act += 0.5;

    dgr_act = dgr_alc(v_alc_act, v_dil_act, dgr_act);
  }
  
  
  
  return dgr_act;
}

int main()
{
  int h = 0;
  scanf("%d", &h);
  printf("%.2f\n", dilution(h));
  return 0;
}