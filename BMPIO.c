#include <stdio.h>


void txtToIm(char txtAdd[], char saveAdd[], char orig[]){
    FILE *fIn = fopen(txtAdd,"rt");
    FILE *fIn2 = fopen(orig,"rb");   
    FILE *fOut = fopen(saveAdd,"wb");
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

void ImTotxt(char imAdd[], char saveAdd[]){
    FILE *fIn = fopen(imAdd,"rb");
    FILE *fOut = fopen(saveAdd,"wt");
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


int main(){
    char add[100] = "standard_test_images/lake.bmp";
    char add1[100] = "standard_test_images/lake2.bmp";
    char add2[100] = "standard_test_images/lake.txt";
    ImTotxt(add,add2);
    txtToIm(add2,add1,add);
}