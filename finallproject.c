#include<stdio.h>
#include<math.h>

void matrice(double small[][10],int big[][512],int s,int b)
{
    int i,j,r,c,ii,jj,t,m=0,n=0,q,p;
    double sum=0;
    ii=s/2;
    r=ii;
    jj=b-r;
    t=b-(2*ii);
    for(r;r<jj && n<t;r++){
        for(c=ii;c<jj && m<t;c++){
            for(i=n,q=0;q<s;i++,q++){
                for(j=m,p=0;p<s;j++,p++){
                    sum=sum+(small[q][p]*big[i][j]);
                }
            }
            big[r][c]=round(sum);
            sum=0;
            m++;
        }
        m=0;
        n++;
    }
}

void ImTotxt(char imAdd[], char saveAdd[]){
    FILE *fIn = fopen("standard_test_images\\cameraman.bmp","rb");
    FILE *fOut = fopen("standard_test_images\\cameraman.txt","wt");
    if (!fIn || !fOut)
    {
        printf("File error.\n");
        return;
    }
    int image[512][512];
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fIn);
    unsigned char pixel[1];
    int width = 512, height = 512;
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            fread(pixel, 1, 1, fIn);
            image[x][y] = pixel[0];
        }
    }
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            fprintf(fOut , "%d ", image[x][y]);
        }
        fprintf(fOut,"\n");
    }
    fclose(fOut);
    fclose(fIn);
    return;
}

void txtToIm(char txtAdd[], char saveAdd[], char orig[]){
    FILE *fIn = fopen("final.txt","rt");
    FILE *fIn2 = fopen("standard_test_images\\cameraman.bmp","rb");   
    FILE *fOut = fopen("result\\cameraman2.bmp","wb");
    if (!fIn || !fOut)
    {
        printf("File error.\n");
        return;
    }
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fIn2);
    fwrite(header, sizeof(unsigned char), 54, fOut);
    int width = 512, height = 512;
    unsigned char pix[3];
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            fscanf(fIn,"%d ",&pix[0]);
            fscanf(fIn,"%d ",&pix[1]);
            fscanf(fIn,"%d ",&pix[2]);
            fwrite(&pix, 3, 1, fOut);
            
        }
    }
    fclose(fOut);
    fclose(fIn);
}

int main()
{
    char add[100] = "standard_test_images/cameraman.bmp";
    char add2[100] = "standard_test_images/cameraman.txt";
    char add1[100] = "standard_test_images/cameraman2.bmp";
   // ImTotxt(add,add2);
    int s,b=512,i,j;
    scanf("%d",&s);
    while (s%2==0 || s>10)
    {
        printf("please enter odd number\n");
        scanf("%d",&s);
    }
    double small[10][10];
    int big[512][512];
    for(i=0;i<s;i++){
        for(j=0;j<s;j++)
        scanf("%lf",&small[i][j]);
    }

    
    FILE *it=fopen("standard_test_images\\cameraman.txt","rt");
    if(!it){
        printf("File error.\n");
        return 0;
    }
    for(i=0;i<512;i++){
        for(j=0;j<512;j++){
            fscanf(it,"%d ",&big[i][j]);
        }
    }
    fclose(it);
    matrice(small,big,s,b);
    for(i=0;i<512;i++){
        for(j=0;j<512;j++){
            if(big[i][j]>0){
                big[i][j]=255;
            }
            if(big[i][j]<0){
                big[i][j]=0;
            }
        }
    }  
    FILE *ot=fopen("final.txt","wt");
    if(!ot){
        printf("File error.\n");
        return 0;
    }
    for(i=0;i<512;i++){
        for(j=0;j<512;j++){
            fprintf(ot,"%d ",big[i][j]);
        }
        printf("\n");
    }
    fclose(ot);
    txtToIm(add2,add1,add); 
    return 0;
}