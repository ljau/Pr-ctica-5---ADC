void calculo(void)
{
   voltaje= valorPot2*.00488281;
   if(voltaje <.5 && voltaje>=0)
   {
      valor=1;
   }
   else if(voltaje <1 && voltaje>=.5)
   {
      valor=2;
   }
   else if(voltaje <1.5 && voltaje>=1)
   {
      valor=4;
   }
   else if(voltaje <2 && voltaje>=1.5)
   {
     valor=8;
   }
   else if(voltaje <2.5 && voltaje>=2)
   {
      valor=16;
   }
   else if(voltaje <3 && voltaje>=2.5)
   {
      valor=32;
   }
   else if(voltaje <3.5 && voltaje>=3)
   {
      valor=64;
   }
   else if(voltaje <4 && voltaje>=3.5)
   {
      valor=128;
   }
   else if(voltaje <4.5 && voltaje>=4)
   {
     valor=256;
   }
   else if(voltaje <5 && voltaje>=4.5)
   {
      valor=512;
   }
   
} 

