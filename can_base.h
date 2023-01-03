typedef unsigned char uint_8;
typedef unsigned short int uint_16;
typedef unsigned int uint_32;
void init_RCC(void);
void init_GPIOA(void);
int init_CAN1(void);
void transmit_CAN1(char *data);
void receive_CAN1(void);
#define 	RCC_BASE   				  (0x40023800U)
#define   RCC_CR							(*((uint_32*) RCC_BASE + 0x00))
#define   HSERDY							(1 << 17)
#define   HSEON               (1 << 16)
#define   RCC_APB1ENR					*((uint_32*)(0x40023840U))
#define   RCC_AHB1ENR					*((uint_32*)(0x40023830U))
#define   CAN1EN							(1 << 25)  //setting apb1 with CAN1
#define   GPIOAEN							(1 << 0)  //setting AHB1 with GPIOA

#define 	GPIO_PORT_A_BASE    (0x40020000U)
#define   GPIOA_MODER					(*(uint_32*)(GPIO_PORT_A_BASE + 0x00))
#define   GPIOA_MODER1				(1 << 0 )    //genreal purpose output
#define   GPIOA_MODER12				(2 << 24 )  //Alternate function mode
#define   GPIOA_OSPEEDR				(*(uint_32*)(GPIO_PORT_A_BASE + 0x08))
#define   GPIOA_OSPEEDR1			(1 << 0 )  //MEDIUM speed upto 50MHz
#define   GPIOA_OSPEEDR12			(1 << 24 )  //MEDIUM speed upto 50MHz
#define   GPIOA_AFRH					(*(uint_32*)(GPIO_PORT_A_BASE + 0x24))	
#define   GPIOA_AFRH12				(9 << 16 )  //CAN1 selection
#define   GPIOA_ODR					  (*(uint_32*)(GPIO_PORT_A_BASE + 0x14))

#define 	CAN1       				  (0x40006400U)
#define 	CAN_MCR             (*((uint_32*)(CAN1 + 0x000U)))
#define 	CAN_MCR_ABOM        (1 << 6)
#define 	CAN_MCR_AWUM        (1 << 5) 
#define 	CAN_MCR_NART        (1 << 4) 
#define 	CAN_MCR_SLEEP       (1 << 1)
#define 	CAN_MCR_INRQ        (1 << 0)
#define 	CAN_MSR             (*(uint_32*)(0x40006400U + 0x004U)) 
#define 	CAN_MSR_TXM         (1 << 8) 
#define 	CAN_MSR_SLAKI       (1 << 4)
#define 	CAN_MSR_WKUI        (1 << 3) 
#define 	CAN_MSR_ERRI        (1 << 2) 
#define 	CAN_MSR_SLAK        (1 << 1) 
#define 	CAN_MSR_INAK        (1 << 0) 
#define 	CAN_MSR_INAK_TIMEOUT   (0xFF)
#define 	CAN_TSR             (*((uint_32*)(0x40006400U + 0x008U)))
#define 	CAN_TSR_LOW2        (1 << 31) 
#define 	CAN_TSR_LOW1        (1 << 30) 
#define 	CAN_TSR_TME0        (1 << 26)
#define 	CAN_TSR_CODE_MASK   (0x3 << 24)
#define 	CAN_TSR_ABRQ2       (1 << 23)
#define 	CAN_TSR_ABRQ1       (1 << 15)   
#define 	CAN_TSR_TERR0       (1 << 3) 
#define 	CAN_TSR_ALST0       (1 << 2) 
#define 	CAN_TSR_TXOK0       (1 << 1)
#define 	CAN_TSR_RQCP0       (1 << 0)
#define 	CAN_IER             (*(uint_32*)(0x40006400U + 0x014U))
#define 	CAN_IER_SLKIE       (1 << 17)
#define 	CAN_IER_WKUIE       (1 << 16)
#define 	CAN_IER_ERRIE       (1 << 15)
#define 	CAN_IER_LECIE       (1 << 11)
#define 	CAN_IER_BOFIE       (1 << 10)
#define 	CAN_IER_EPVIE       (1 << 9)
#define 	CAN_IER_EWGIE       (1 << 8)  
#define 	CAN_IER_TMEIE       (1 << 0)
#define 	CAN_BTR             (*(uint_32*)(0x40006400U + 0x01CU))
#define 	CAN_BTR_SILM        (1U << 31)
#define 	CAN_BTR_LBKM        (1U << 30)
#define 	CAN_BTR_SJW_1TQ     (0x0 << 24) 
#define 	CAN_BTR_SJW_2TQ     (0x1 << 24) 
#define 	CAN_BTR_SJW_3TQ     (0x2 << 24) 
#define 	CAN_BTR_SJW_4TQ     (0x3 << 24) 
#define 	CAN_BTR_SJW_MASK    (0x3 << 24) 
#define 	CAN_BTR_TS2_1TQ     (0x0 << 20) 
#define 	CAN_BTR_TS2_2TQ     (0x1 << 20) 
#define 	CAN_BTR_TS2_3TQ     (0x2 << 20)
#define 	CAN_BTR_TS2_4TQ     (0x3 << 20)
#define 	CAN_BTR_TS2_5TQ     (0x4 << 20)
#define 	CAN_BTR_TS2_6TQ     (0x5 << 20) 
#define 	CAN_BTR_TS2_7TQ     (0x6 << 20) 
#define 	CAN_BTR_TS2_8TQ     (0x7 << 20) 
#define 	CAN_BTR_TS2         (0x02 << 20) 
#define 	CAN_BTR_TS1_1TQ     (0x0 << 16) 
#define 	CAN_BTR_TS1_2TQ     (0x1 << 16) 
#define 	CAN_BTR_TS1_3TQ     (0x2 << 16) 
#define 	CAN_BTR_TS1_4TQ     (0x3 << 16) 
#define 	CAN_BTR_TS1_5TQ     (0x4 << 16) 
#define 	CAN_BTR_TS1_6TQ     (0x5 << 16) 
#define 	CAN_BTR_TS1_7TQ     (0x6 << 16) 
#define 	CAN_BTR_TS1_8TQ     (0x7 << 16) 
#define 	CAN_BTR_TS1_9TQ     (0x8 << 16) 
#define 	CAN_BTR_TS1_10TQ    (0x9 << 16) 
#define 	CAN_BTR_TS1_11TQ    (0xA << 16) 
#define 	CAN_BTR_TS1_12TQ    (0xB << 16)
#define 	CAN_BTR_TS1_13TQ    (0xC << 16) 
#define 	CAN_BTR_TS1_14TQ    (0xD << 16)
#define 	CAN_BTR_TS1_15TQ    (0xE << 16) 
#define 	CAN_BTR_TS1_16TQ    (0xF << 16)
#define 	CAN_BTR_TS1         (0x07 << 16)
#define 	CAN_BTR_BRP         (0x01 << 0) //for 500kbps - 2000ns=tq+xtq+ytq //get tq as one part of 10
#define 	CAN_MBOX0  				  0x180U
#define 	CAN_TI0R            (*((uint_32*)(0x40006400U + 0x180U)))
#define 	CAN_TI0R_STID_MASK  (0x0F << 21) 
#define 	CAN_TI0R_EXID_MASK  (0x0FFFFFF << 3)  
#define 	CAN_TI0R_IDE        (1 << 2) 
#define 	CAN_TI0R_RTR        (1 << 1) 
#define 	CAN_TI0R_TXRQ       (1 << 0) 
#define 	CAN_TDT0R           (*((uint_32*)(0x40006400U + 0x184U)))
#define 	CAN_TDT0R_TIME_MASK (0xFFFF << 15) 
#define 	CAN_TDT0R_TGT       (1 << 5) 
#define 	CAN_TDT0R_DLC_MASK  (0xF)
#define 	CAN_TDL0R           (*(uint_32*)(CAN1 + CAN_MBOX0 + 0x08U))
#define 	CAN_TDH0R           (*(uint_32*)(CAN1 + CAN_MBOX0 + 0x0CU))

#define 	CAN_FMR             (*(uint_32*)(CAN1 + 0x200))
#define 	CAN_FMR_FINIT         (1 << 0)
#define 	CAN_FMR_CAN2SB_SHIFT  (1 << 8) //for using only one filter
#define 	CAN_FM1R            (*(uint_32*)(CAN1 + 0x204))
#define 	CAN_FM1R_init       (0 << 0)     //mask mode
#define 	CAN_FS1R            (*(uint_32*)(CAN1 + 0x20C))
#define   CAN_FS1R_SET        (0x01)
#define 	CAN_FFA1R           (*(uint_32*)(CAN1 + 0x214)) 
#define 	CAN_FFA1R_SET_FIFO  (0x00)
#define 	CAN_FA1R            (*(uint_32*)(CAN1 + 0x21C))
#define 	CAN_FA1R_ACTIVE     (0X01)
#define 	CAN_F0R_ID					(*(uint_32*)(CAN1 + 0x240 + (0)*0X08 + 0X00)) //addressing each bank by multiplying it with 8 to get next 8 bytes ie,64 bits(id32+mask32)
#define 	CAN_F0R_ID_SET			(0x0F << 21)|(1<<1)
#define 	CAN_F0R2_MASK       (*(uint_32*)(CAN1 + 0x240 + (0)*0X08 + 0X04)) //here for mask register we add 4 bytes ie, 32 bits  
#define 	CAN_F0R2_MASK_SET		(0x0F << 21)|(1<<1)

#define 	CAN_MSR_RXM         (1 << 9)
#define 	CAN_RI0R  				  (*(uint_32*)(CAN1 + 0x1B0))
#define   CAN_RI0R_STID       (0x0F << 21)
#define   CAN_RI0R_IDE        (0x00)
#define   CAN_RI0R_RTR        (1<<1)
#define 	CAN_RI1R 					  (*(uint_32*)(CAN1 + 0x1C0))
#define 	CAN_RI1R_FMI        (0 << 8)
#define 	CAN_RI1R_DLC        (0xF)
#define 	CAN_RDT0R           (*(uint_32*)(CAN1 + 0x1B4))
#define 	CAN_RDT1R           (*(uint_32*)(CAN1 + 0x1C4))
#define   CAN_RDL0R						(*(uint_32*)(CAN1 + 0x1B8))
#define   CAN_RDH0R						(*(uint_32*)(CAN1 + 0x1BC))
union 
	{
     uint_8 data8[4];
     uint_32 data32;
  } TXDL,TXDH;

union 
	{
     uint_8 data8[4];
     uint_32 data32;
  } RXDL,RXDH;


