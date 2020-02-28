#include "../Service/TMU/TMU.h"
#include "../Service/TMU/TMU_PbCfg.h"
#include "TMU_Test_Cases.h"
#include "stdio.h"

#define TMU_TIMER_5 5

/*
*TMU_Init_TestCases prototype
*/

static void TMU_Init_TestCase_0(void);
static void TMU_Init_TestCase_1(void);
static void TMU_Init_TestCase_2(void);
static void TMU_Init_Senario_0(void);

/*
*TMU_Start_TestCase prototype
*/

static void TMU_Start_TestCase_0(void);
static void TMU_Start_TestCase_1(void);
static void TMU_Start_TestCase_2(void);
static void TMU_Start_TestCase_3(void);
static void TMU_Start_TestCase_4(void);
static void TMU_Start_TestCase_5(void);


/*
*TMU_Stop_TestCases prototype
*/

static void TMU_STOP_TestCase_0(void);
static void TMU_STOP_TestCase_1(void);
static void TMU_STOP_TestCase_2(void);


/*
*TMU_Dispature_TestCase prototype
*/
static void TMU_Dispature_TestCase_0(void);


/*
*TMU__DeInit_TestCase prototype
*/
static void TMU_DeInit_TestCase_0(void);


static void (*TMU_Init_TestCasesFun[4])(void)={ TMU_Init_TestCase_2,TMU_Init_TestCase_1,TMU_Init_TestCase_0,TMU_Init_Senario_0};

static void (*TMU_Start_TestCasesFun[6])(void)={ TMU_Start_TestCase_0,TMU_Start_TestCase_1,TMU_Start_TestCase_2,TMU_Start_TestCase_3,TMU_Start_TestCase_4,TMU_Start_TestCase_5};

static void (*TMU_Stop_TestCasesFun[3])(void)={TMU_STOP_TestCase_0,TMU_STOP_TestCase_1,TMU_STOP_TestCase_2};





/*TMU_Init_TestCases_FUNCTION Implementation */

static void TMU_Init_TestCase_0(void){
	
	char ErrorStatus = 0;
	
	strTMU_Cfg_t gstr_TMU_PbCfg = {TMU_TIMER_0 ,1} ;
	
	printf("Test case 0: Correct Parameter :");
	
	ErrorStatus=TMU_Init(&gstr_TMU_PbCfg);
	
	if(ErrorStatus==E_OK)
	
	printf(" PASS\n\n\n");
	
	else 
	
		printf(" Faild\n\n\n");
}

static void TMU_Init_TestCase_1(void){
	
	char ErrorStatus = 0;
	
	strTMU_Cfg_t gstr_TMU_PbCfg ;
	
	printf("Test case 1: Passing NULL Pointer :");
				
	ErrorStatus=TMU_Init(NULL);
	
	if(ErrorStatus==ERROR_NULL_PTR+ MODULE_ERROR_NUMBER)
		
		printf(" PASS\n\n\n");
	
	else 
		
	printf("Faild\n\n\n");
}

static void TMU_Init_TestCase_2(void){
	
	char ErrorStatus=0;
	
	strTMU_Cfg_t gstr_TMU_PbCfg = {TMU_TIMER_5 ,1} ;
	
	printf("Test case 2: Passing Invalid Timer channel ID :");
	
	ErrorStatus=TMU_Init(&gstr_TMU_PbCfg);
	
	if(ErrorStatus==ERROR_INVALIDE_PARAMETAR+ MODULE_ERROR_NUMBER )
		printf(" PASS\n\n\n");
	else 
		printf("Faild\n\n\n");
}

static void TMU_Init_Senario_0(void){
	
	char ErrorStatus = 0;
	
	strTMU_Cfg_t gstr_TMU_PbCfg = {TMU_TIMER_0 ,1} ;
	
	printf("senario  0: Multiple Defintion of TMU:");
	
	
	ErrorStatus=TMU_Init(&gstr_TMU_PbCfg);
	
	ErrorStatus=TMU_Init(&gstr_TMU_PbCfg);
	
	if(ErrorStatus==ERROR_MULTIPLE_INIT+ MODULE_ERROR_NUMBER)
		
		printf(" PASS\n\n\n");
	
	else 
		
		printf("Faild\n\n\n");
}

extern void Test_TMU_InilFun(void){
	
	char Test_Case_Stage=0;
	
	printf("\n                      TEST TMU INIT FUNCTION\n\n");
	
	for( ; Test_Case_Stage < 4 ; Test_Case_Stage ++ )
	{
		TMU_Init_TestCasesFun[Test_Case_Stage]();
		
	}
}

/* *********************************************************************************************************************/

/* TEST_CASES OF TMU_START_FUNCTION  Implementation */

static void TMU_Start_TestCase_0(void){
	
	char ErrorStatus = 0;
	
	printf("TMU_Start_Test Case_0 : NULL cnsumer adderess");
	
	ErrorStatus=TMU_Start_Timer(1,1,0,NULL);
	
	if (ErrorStatus==MODULE_ERROR_NUMBER+ERROR_NULL_PTR)
		
		printf(" PASS\n\n\n");
	
	else 
		
		printf("Faild\n\n\n");
}

static void TMU_Start_TestCase_1(void){
	
	char ErrorStatus = 0;

	void add (void){}
	
	printf("TMU_Start_Test Case_1: Calling Start Without Inli.");
	
	
	ErrorStatus=TMU_Start_Timer(1,1,0,add);
	
	if (ErrorStatus==MODULE_ERROR_NUMBER+ERROR_UNILTILZED_MODULE)
		
		printf(" PASS\n\n\n");
	
	else 
		
		printf("Faild\n\n\n");
	
}

static void TMU_Start_TestCase_2(void){
	
	char ErrorStatus = 0;
	
	void add (void){}
	
	strTMU_Cfg_t gstr_TMU_PbCfg = {TMU_TIMER_0 ,1} ;
	
	TMU_Init(&gstr_TMU_PbCfg);
	
	printf("TMU_Start_Test Case_2: Invalid consumer Id");
	
	ErrorStatus=TMU_Start_Timer(1,1,3,add);
	
	if (ErrorStatus==MODULE_ERROR_NUMBER+ERROR_INVALIDE_PARAMETAR)
		
		printf(" PASS\n\n\n");
	
	else 
		
		printf(" Faild\n\n\n");
	
}

static void TMU_Start_TestCase_3(void){
	
	char ErrorStatus = 0;
	
	void add (void){}

	printf("TMU_Start_Test Case_3: Invalid TMU Mode");
	
	
	ErrorStatus=TMU_Start_Timer(1,3,0,add);
	
	if (ErrorStatus==MODULE_ERROR_NUMBER+ERROR_INVALIDE_PARAMETAR)
		
		printf(" PASS\n\n\n");
	
	else 
		
		printf("Faild\n\n\n");
	
}

static void TMU_Start_TestCase_4(void){
	
	char ErrorStatus = 0;
	
	void add (void){}

	printf("TMU_Start_Test Case_4: creat two diffrent consumer in same ID :");
	
	TMU_Start_Timer(1,0,0,add);
	
	ErrorStatus=TMU_Start_Timer(1,0,0,add);
	
	if (ErrorStatus==MODULE_ERROR_NUMBER+ERROE_EXIST_ID)
		
		printf(" PASS\n\n\n");
	
	else 
		
		printf("Faild\n\n\n");
	
}

static void TMU_Start_TestCase_5(void){
	
	char ErrorStatus = 0;
	
	void add (void){}

	printf("TMU_Start_Test Case_5: FULL Consumer Buffer :");
	
	TMU_Start_Timer(1,1,1,add);
	
	ErrorStatus=TMU_Start_Timer(1,1,1,add);
	
	if (ErrorStatus==MODULE_ERROR_NUMBER+ERROR_FULL_BUFFER)
		
		printf(" PASS\n\n\n");
	
	else 
		
		printf("%d Faild\n\n\n",ErrorStatus );
	
}

extern void Test_TMU_StartFun(void){
	char Test_Case_Stage=0;
	 
	printf(" \n                        TEST TMU START FUNCTION \n\n");
	
	for( ; Test_Case_Stage < 6 ; Test_Case_Stage ++ )
	{
		TMU_Start_TestCasesFun[Test_Case_Stage]();
		
	}
}

/* *********************************************************************************************************************/
/* TEST_CASES OF TMU_STOP_FUNCTION  Implementation*/

static void TMU_STOP_TestCase_0(void){
	
	char ErrorStatus = 0;
	
	printf("TMU_Stop_Test Case_0: Calling stop Without Inli. :");
	
	
	ErrorStatus=TMU_Stop_Timer(1);
	
	if (ErrorStatus==MODULE_ERROR_NUMBER+ERROR_UNILTILZED_MODULE)
		
		printf(" PASS\n\n\n");
	
	else 
		
		printf(" Faild\n\n\n");
}

static void TMU_STOP_TestCase_1(void){
	
	char ErrorStatus = 0;
	
	strTMU_Cfg_t gstr_TMU_PbCfg = {TMU_TIMER_0 ,1} ;
	
	TMU_Init(&gstr_TMU_PbCfg);
	
	printf("TMU_Stop_Test Case_1 : Stop Empty Buffer");
	
	
	ErrorStatus=TMU_Stop_Timer(1);
	
	if (ErrorStatus==MODULE_ERROR_NUMBER+ERROR_EMPTY_BUFFER)
		
		printf(" PASS\n\n\n");
	
	else 
		
		printf("Faild\n\n\n");
}

static void TMU_STOP_TestCase_2(void){
	
	void add (void){}
	
	printf("TMU_Stop_Test Case_2: Stop Not exist element :");
	
	TMU_Start_Timer(1,1,0,add);
	
	if (TMU_Stop_Timer(1)==MODULE_ERROR_NUMBER+ERROR_ELEMENT_NOT_EXIST)
		
		printf(" PASS\n\n\n");
	
	else 
		
		printf("Faild\n\n\n");
}

extern void Test_TMU_StopFun(void){
	char Test_Case_Stage=0;
	 
	printf("\n                   TEST TMU STOP FUNCTION \n\n");
	
	for( ; Test_Case_Stage < 3 ; Test_Case_Stage ++ )
	{
		TMU_Stop_TestCasesFun[Test_Case_Stage]();
		
	}
}

/* *********************************************************************************************************************/
/* TEST_CASES OF TMU_Dispature_FUNCTION  Implementation */

static void TMU_Dispature_TestCase_0(void){
	
	printf("TMU_Dispature_Test Case_0: Calling Dispature Without Inli. :");
	
	if(TMU_Dispatcher()==MODULE_ERROR_NUMBER+ERROR_UNILTILZED_MODULE)
		
		printf(" PASS\n\n\n");
	
	else 
		
		printf(" Faild\n\n\n");
		
}

extern void Test_TMU_DispatureFun(void){
	
	printf(" \n                   TEST TMU Dispature FUNCTION \n\n");
	
	TMU_Dispature_TestCase_0();
}


/* *********************************************************************************************************************/

/* TEST_CASES OF TMU_DEINT_FUNCTION  Implementation */

static void TMU_DeInit_TestCase_0(void){
	
	printf("TMU_DeInit_Test Case_0: Calling DeInit Without Inli. :");
	
	if(TMU_DeInit()==MODULE_ERROR_NUMBER+ERROR_UNILTILZED_MODULE)
		
		printf(" PASS\n\n\n");
	
	else 
		
		printf(" Faild\n\n\n");
		
}

extern void Test_TMU_DeInitFun(void){
	
	printf("\n                   TEST TMU DeInit FUNCTION \n\n");
	TMU_DeInit_TestCase_0();
}

















