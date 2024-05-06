extern signed char setPwm(signed char duty, signed char safety_intervention);

void main(void)
{
  signed char req_duty;
  signed char req_safety_intervention;
  for (req_duty = -128; req_duty <= 127; req_duty++)
    for (req_safety_intervention = -128; req_safety_intervention <= 127; req_safety_intervention++)
      if (req_duty >= 0 && req_duty <= 100)
        setPwm(req_duty, req_safety_intervention);
}
