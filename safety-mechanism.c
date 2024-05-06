#define PWM_Channel ((uint16) 55U)

typedef unsigned short uint16;
typedef float float32;
typedef uint16 Pwm_ChannelType;

/*@
  terminates \true;
  exits \false;
  ensures \true;
  assigns \nothing;
*/
extern void Pwm_SetDutyCycle(Pwm_ChannelType ChannelNumber, uint16 DytyCycle);

/*@
    requires duty <= 100;
    requires duty >= 0;

    terminates \true;
    exits \false;

    assigns \nothing;
    ensures safety_intervention != 0 ==> \result == 0;
    ensures safety_intervention == 0 && duty <= 100 ==> \result <= 0x8000;
    ensures safety_intervention == 0 && duty <= 50  ==> \result <= 0x4000;
    ensures safety_intervention == 0 && duty == 50  ==> \result >= 0x3fff;
    ensures safety_intervention == 0 && duty == 0   ==> \result == 0x0000;

 */
uint16 setPwm(unsigned char duty, int safety_intervention)
{
  uint16 actuated_duty = safety_intervention != 0 ? 0U : (uint16)((0x8000U * duty) / 100);

  //Pwm_SetCycle(PWM_Channel, actuated_duty);

  return actuated_duty;
}

void trig(int duty, int safety) {
  if (duty <= 100 && duty >= 0)
    setPwm(duty, safety);
}
