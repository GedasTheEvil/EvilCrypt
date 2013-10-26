#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <iostream>

// version 0.2

using namespace std;

int main(int argc, char *argv[])
{
    ifstream keyF("data/main.key");
    int keyL;
    keyF >> keyL;
    char key[keyL];
    keyF >> key;
    keyF.close();    
       
    char filename[255], filename2[255],tmp[255];
    
    
      if (argc >= 2)
      {
         if(strcmp(argv[1], "-i") == 0)
         {
            printf("opening file %s [args]\n",argv[2]);
            sprintf(filename,"%s",argv[2]);
            sprintf(filename2,"%s.decrypted",argv[2]);
         }
         else {printf("The arguments were [%s] and [%s]\n",argv[1],argv[2]); return 0;}
      }
      else 
      {
         printf("opening file %s [noargs]\n","target.jpg");
         sprintf(filename,"%s","target.jpg");
         printf("Filename is'%s'\n",filename);
         sprintf(filename2,"%s.decrypted","target.jpg");
         printf("Filename2 is'%s'\n",filename2);
      }

    sprintf(tmp,"stat -c%%s \"%s\" > data/fs.dmp",filename);
    system(tmp);
    
    ifstream fss("data/fs.dmp");
    int filesize = 0;
    fss >> filesize;
    fss.close();
    
    FILE *f, *fw;
    f  = fopen(filename,"rb");
    fw = fopen(filename2,"wb");
    
    char c = 'a';
    
    int iter = 0;
    
    int n=0;
    
    if(f == NULL)printf("Could not open file");
    else
    {
        do
        {
            c = fgetc (f);
	    if(n < filesize)
	    {
	      if( iter >= keyL)iter = 0;
	      fputc(c - key[iter],fw);
	      iter++;
              if(n % (filesize / 1000) == 0)
                 cout << "Decrypting: " << ((float)n / (float)filesize * 100.0) << "%\r" << std::flush;
	    }
            n++;
            
        } while (n < filesize);
    }
    
    fclose(f);
    fclose(fw);
    
    printf("\n\nRead %d bytes\n",n);

} 
