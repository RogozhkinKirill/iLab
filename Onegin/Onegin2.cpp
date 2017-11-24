#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

char** AlphaSort (char *pBuffer , size_t LenF , int *pcStr);
char** AlignPtr  (char *pBuffer , size_t LenF , int *pcStr);
int    Compare   (const void *pStr1 , const void *pStr2);

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

	char *pBuffer = (char*)malloc( ((int)LenF + 1) * sizeof(char));
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
		if(pBuffer[cEl] == '�')
		{
			pBuffer[cEl] = '�';
		}
		if(pBuffer[cEl] == '�')
		{
			pBuffer[cEl] = '�';
		}
    }


	char **pStr = AlphaSort(pBuffer , LenF , &cStr);
	if(!pStr)
	{
		printf("Error. main. Pointer on Str = NULL");
		return 0;
	}

    for(int count1=0; count1<cStr; ++count1)
    {
		fputs(pStr[count1] , pBred);
		fprintf(pBred , "\n");
//		puts(pStr[count1]);
    }

    fclose(pOnegin);
    free(pBuffer);

	fclose(pBred);


    return 0;
}

char** AlphaSort(char *pBuffer , size_t LenF , int *pcStr)
{
	if(pBuffer)
	{
		char **pStr = AlignPtr(pBuffer , LenF , pcStr);

        if(!pBuffer)
        {
			printf("Error. AlphaSort. Pointer on Buffer = NULL");
			return NULL;
        }

		qsort(pStr , *pcStr , sizeof(char**) , Compare);

		return pStr;
	}
	else
	{
		printf("Error. AlphaSort. Pointer on Buffer = NULL");
		return NULL;
	}
}


char** AlignPtr(char *pBuffer , size_t LenF , int *pcStr)
{
	if(pBuffer)
	{
		char **pStr = (char**)malloc(*pcStr * sizeof(char*));
		int count1 = 0;
		for(int NumStr=0; NumStr<*pcStr; ++NumStr)
		{
			int cRound = 0;
			for(count1; count1<(int)LenF + 1; ++count1)
			{
				if(cRound == 0 && pBuffer[count1] >= -64 && pBuffer[count1] <= -1)
				{
					pStr[NumStr] = &pBuffer[count1];
					cRound++;
				}
				if(cRound == 0 && pBuffer[count1] == '\0')
				{
					*pcStr -= 1; // Ïî÷åìó íå ðàáîòàåò êîíñòðóêöèÿ *pcStr--
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
		}

		return pStr;
	}
	else
	{
		printf("Error. AlignPtr. Pointer on Buffer =  NULL");
		return NULL;
	}
}

int Compare(const void *pStr1 , const void *pStr2)
{
	return strcmp(*(char**)pStr1  , *(char**)pStr2);
}
