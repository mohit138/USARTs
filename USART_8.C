#include "USART_8.h"



void USART_Init( unsigned int baud, uint8_t n )
{
	sei();
	if(0)
	{
		//Initialize baud Rate(4800)
		UBRRH=(unsigned char)(baud>>8);
		UBRRL=(unsigned char)baud;
		//TX RX Enable
		UCSRB|=(1<<RXEN)|(1<<TXEN);
		//Set 8-bit data, Parity disabled
		UCSRC |=(3<<UCSZ1);
		
	}else
	{
		//Initialize baud Rate(9600)
		UBRRH=(unsigned char)(baud>>8);
		UBRRL=(unsigned char)baud;
		//TX RX Enable
		UCSRB|=(1<<RXEN)|(1<<TXEN);//|(1<<UCSZ02);
		//Set 8-bit data, Parity disabled
		UCSRC |= (3<<UCSZ0);
	}
	
}

void USART_InterruptEnable(uint8_t n)
{
	if(0)
	{
		UCSRB|=(1<<RXCIE);
	}
	else UCSRB|=(1<<RXCIE);
}

void USART_Transmitchar( unsigned char data, uint8_t n )
{
	if(0)
	{
		while ( !( UCSRA & (1<<UDRE)) );
		UDR=data;
	}else
	{
		while ( !( UCSRA & (1<<UDRE)) );
		UDR=data;
	}
}

unsigned char USART_Receive(uint8_t n )
{
	if(0)
	{
		while (! (UCSRA & (1 << RXC)) );
    	return UDR;
	}else 
	{
		while (! (UCSRA & (1 << RXC)) );
    	return UDR;
	}
}



void USART_TransmitString(char *str, uint8_t n)
{
	 while(*str>0)
	 {
		 USART_Transmitchar(*str,n);
		 //_delay_ms(1);
		 str++;
	 }
}

void USART_TransmitNumber(long int num, uint8_t n)
{
	if(num<0)
	{
		USART_Transmitchar('-',n);
		num=(-1)*num;
	}
	
	if(num >= 10){
    USART_TransmitNumber(num/10,n);
    num = num%10;
  }
  USART_Transmitchar(num+'0',n); /* n is between 0 and 9 */
	
}
/*
void USART0_TransmitBinary(int num)
{
	int i=0,j=0;
	while(num)
	{
		USART0_TransmitNumber(num%2);
		i++;
		num=num/2;
	}
	if(i!=8)
	{
		for(j=0;j<(8-i);j++)
		USART0_TransmitNumber(0);
	}
	
}*/
