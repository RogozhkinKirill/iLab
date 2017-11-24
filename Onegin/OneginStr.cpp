#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


typedef struct ArrStr
{
	char *pStr;
	size_t Len = 0;
} ArrStr;

typedef ArrStr *pArrStr;



pArrStr Sort 	 (char *pBuffer , size_t LenF , int *pcStr);
pArrStr AlignPtr (char *pBuffer , size_t LenF , int *pcStr);
int    Compare  (const void *pArr1 , const void *pArr2);
void Reverse    (pArrStr pArr , int *pcStr);



int main()
{
    setlocale(LC_ALL , "RUS");

    printf("Text file operations\n");

    FILE *pOnegin = fopen("C:\\Onegin.txt", "r");
    FILE *pBred   = fopen("C:\\Bred.txt", "w");

    if(pOnegin == NULL)
    {
            printf("Problems\n");

            return 0;
    }

	fseek(pOnegin , 0 , SEEK_END);
	long LenF = ftell(pOnegin);
	rewind (pOnegin);
	printf("%ld\n" , LenF);

	char *pBuffer = (char*)calloc((int)LenF + 1 , sizeof(char));
    if(!pBuffer)
    {
		printf("Error. Pointer on Buffer = NULL");
		return 0;
    }
    pBuffer[LenF] = '\n';


    size_t result = fread(pBuffer , sizeof(char) , LenF , pOnegin);

    //puts(pBuffer);

	int cStr = 0;
	int cEl = 0;
    for(cEl=0; cEl<LenF + 1; ++cEl)
    {
		if(pBuffer[cEl] == '\n')
		{
			pBuffer[cEl] = '\0';
			++cStr;
		}
		if(pBuffer[cEl] == '¸') //I meant [yo]->[ye] letters Cyrillic alphabet(lowercase)
		{
			pBuffer[cEl] = 'å';
		}
		if(pBuffer[cEl] == '¨')//I meant [yo]->[ye] letters Cyrillic alphabet(capital)
		{
			pBuffer[cEl] = 'Å';
		}
    }


	pArrStr psArr = Sort(pBuffer , LenF , &cStr);
	if(!psArr)
	{
		printf("Error. main. Pointer on Str = NULL");
		return 0;
	}

    for(int count1=0; count1<cStr; ++count1)
    {
		fputs(psArr[count1].pStr , pBred);
		fprintf(pBred , "\n");
		puts(psArr[count1].pStr);
    }

    free(pBuffer);
    free(psArr);

	fclose(pOnegin);
	fclose(pBred);


    return 0;
}

pArrStr Sort(char *pBuffer , size_t LenF , int *pcStr)
{
	if(pBuffer)
	{
		pArrStr pArr = AlignPtr(pBuffer , LenF , pcStr);

        if(!pBuffer)
        {
			printf("Error. AlphaSort. Pointer on Buffer = NULL");
			return NULL;
        }


        printf("Do you want to sort by alphabet(print 1) or by rhymes(print 2)?\n");
        int Route = 0;
        scanf("%d" , &Route);

        if( (Route != 1) && (Route != 2) )
        {
			while(Route)
			{
				printf("I asked you to print 1 or 2(\n\n");
				printf("Try again\n");
				printf("Do you want to sort by alphabet(print 1) or by rhymes(print 2)?\n");
				scanf("%d" , &Route);

				if( (Route == 1) || (Route == 2) )
					break;
			}
		}

		if(Route == 1)
		{
			qsort(pArr , *pcStr , sizeof(ArrStr) , Compare);
		}
        else
        {
			Reverse(pArr , pcStr);

			qsort(pArr , *pcStr , sizeof(ArrStr) , Compare);

			Reverse(pArr , pcStr);
		}

		return pArr;
	}
	else
	{
		printf("Error. AlphaSort. Pointer on Buffer = NULL");
		exit(EXIT_FAILURE);
	}
}


pArrStr AlignPtr(char *pBuffer , size_t LenF , int *pcStr)
{
	if(pBuffer)
	{
		char A = 'À'; //I meant 1st letter Cyrillic alphabet (Capital)
		char z = 'ÿ'; //I meant last letter Cyrillic alphabet (lowercase)

		pArrStr pArr = (pArrStr)calloc(*pcStr , sizeof(ArrStr));
		int count1 = 0;
		for(int NumStr=0; NumStr<*pcStr; ++NumStr)
		{
			int cRound = 0;
			int BeginStr = count1;
			for(count1; count1<(int)LenF + 1; ++count1)
			{
				if(cRound == 0 && pBuffer[count1] >= A && pBuffer[count1] <= z)
				{
					pArr[NumStr].pStr = &pBuffer[count1];
					cRound++;
				}
				if(cRound == 0 && pBuffer[count1] == '\0')
				{
					(*pcStr)--;
					NumStr--;
					count1++;

					break;
				}
				if(pBuffer[count1] == '\0')
				{
					count1++;
					break;
				}
			}
			int count2 = count1 - 1;
			while(pBuffer[count2 - 1] == ' ')
			{
				--count2;
			}
			if(count2 != count1 - 1)
			{
				pBuffer[count2] = '\0';
			}
			pArr[NumStr].Len = count2 - BeginStr;
		}
		return pArr;
	}
	else
	{
		printf("Error. AlignPtr. Pointer on Buffer =  NULL");
		return NULL;
	}
}

int Compare(const void *pArr1 , const void *pArr2)
{
	ArrStr Str1 = *(pArrStr)pArr1;
	ArrStr Str2 = *(pArrStr)pArr2;


	return strcmp(Str1.pStr , Str2.pStr);;
}

void Reverse(pArrStr pArr , int *pcStr)
{
	if(pArr)
	{

		for(int count1=0; count1<*pcStr; ++count1)
		{
			for(int cEl=0; cEl<(pArr[count1].Len/2 + 1); ++cEl)
			{
				char RevEl = 0;
				RevEl = pArr[count1].pStr[cEl];
				pArr[count1].pStr[cEl] = pArr[count1].pStr[pArr[count1].Len - cEl - 1];
				pArr[count1].pStr[pArr[count1].Len - cEl - 1] = RevEl;
			}
		}
	}
	else
	{
		printf("Error. Pointer on Arr = NULL");
		exit(EXIT_FAILURE);
	}
}
