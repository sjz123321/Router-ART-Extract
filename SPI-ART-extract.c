#include<stdio.h>
#include<stdlib.h>
#include<string.h>
unsigned char block=0xff;					//define a empty byte_block
int main(int argc,char **argv)
{
	char src_PATH[255];						//src bin file path
	if(argc>1) strcpy(src_PATH,*(argv+1));	//try to get PATH from argument
	else									//input file PATH mannually
	{
		printf("please enter your BIN file PATH:\n");
		scanf("%s",src_PATH);
	}
	FILE  *src=NULL,*dst=NULL;
	fpos_t src_lenth=0,dst_lenth=0;
	if((src=fopen(src_PATH,"rb"))==NULL) 
	{
		fprintf(stdout,"File not exist!\n");
		goto error;
	}		
	fseek(src,0L,SEEK_END);						//move FILE pointer to FILE_END
	
	
	
	if(fgetpos(src,&src_lenth)) goto error;		//get FILE lenth
	if(src_lenth==0)							//empty src file error
	{
		fprintf(stdout,"Invaild PATH or File name!\n");
		goto error;
	}
	if(src_lenth%1024) 							//src file lenth error
	{
		fprintf(stdout,"File lenth error.\nplease check your file!");
		goto error;
	}
	
	
	
	
	
	if((dst=fopen("ART_OUTPUT.BIN","wb+"))==NULL) //create dst file
	{
		fprintf(stdout,"Can not write File,plese check your authority!\n");
		goto error;
	}
	for(int i=0;i<64*1024;i++)					//write empty block to dst file
	{
		fwrite(&block,sizeof(unsigned char),1,dst);
	}
	fclose(dst);								//create file successfully.
	
	
	
	
	
	switch(src_lenth/1024)						//To judge the run mode 
	{
		case 1024:
			{
				if((dst=fopen("ART_OUTPUT.BIN","rb+"))==NULL) //reopen OUTPUT_FILE
				{
					fprintf(stdout,"Can not open File,Plese check!\n");
					goto error;
				}
				fseek(src,-4080L,SEEK_END); //redirect FILE pointer to file open (0xFFFFF-0xFF00F)
				fseek(dst,4096,SEEK_SET); //prepare dst FILE pointer
				unsigned char src_data_byte=0x00;			//src data byte
				for(int i=0;i<4080;i++)
				{
					src_data_byte=0x00;
					fread(&src_data_byte,sizeof(char),1,src);
					fwrite(&src_data_byte,sizeof(char),1,dst);
				}
				break;
			}
		default:
			{
				if((dst=fopen("ART_OUTPUT.BIN","rb+"))==NULL) //reopen OUTPUT_FILE
				{
					fprintf(stdout,"Can not open File,Plese check!\n");
					goto error;
				}
				fseek(src,-65536L,SEEK_END);
				unsigned char src_data_byte=0x00;			//src data byte
				for(int i=0;i<64*1024;i++)					//write data
				{
					src_data_byte=0x00;
					fread(&src_data_byte,sizeof(char),1,src);
					fwrite(&src_data_byte,sizeof(char),1,dst);
				}
				break;
			}
	}
	//printf("%ld",src_lenth/1024);
	printf("ART File extract successfully!\n"); 
	fclose(src);
	fclose(dst);
	exit(0);
	
	
	
	
	error:
	printf("IO ERROR!");
	if(src!=NULL) fclose(src);
	if(dst!=NULL) fclose(dst);
	exit(-1);
}

