byte flags=0;
#bit channelFlag = flags.0
#bit newsamplig=flags.1
int switchCounter=0;
int samplingCounter=0;
int16 binaryBuffer=0;
int16 segmentBox=0;
int16 portSegment=0;
int16 portBinary=0;

#INT_AD
void AD_isr(void)
{
   if(switchCounter>=3&&newsamplig==0)
   {
      read_adc(ADC_START_ONLY);
      if(channelFlag==0)
      {
         binaryBuffer=binaryBuffer+read_adc(ADC_READ_ONLY);
         set_adc_channel(1);
         channelFlag=1;
         samplingCounter++;
         if(samplingCounter>=10)
         {
         samplingCounter=0;
         newsamplig=1;
         }
      }
      else
      {
         segmentBox=read_adc(ADC_READ_ONLY);
         set_adc_channel(0);
         channelFlag=0;
      }
      switchCounter=0;
   }   
}
#int_timer0
void timer_0()
{
   switchCounter++;
   set_timer0(0);
}
