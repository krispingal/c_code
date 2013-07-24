//This program uses caesar's cipher to encrypt and
//decrypt any given message

#include<stdio.h>

void encrypt(int key ,char mesg[]){
	int i;
	char t;
	for(i = 0;mesg[i] !=  '\0';i++){
		if(mesg[i] >= 'a' && mesg[i] <= 'z'){
			t = 'a';
			if (mesg[i] + key > 'z')
				t = t +(mesg[i] + key - 'z');
			else
				t = mesg[i] + key;
		}
		else if (mesg[i] >= 'A' && mesg[i] <= 'Z'){
			t = 'A';
			if (mesg[i] + key > 'Z')
				t = t +(mesg[i] + key -'Z');
			else
				t = mesg[i] + key;
		}
		else
			t = mesg[i] + key;
		mesg[i] = t;
	}
	return ;
}

void decrypt(int key ,char mesg[]){
	int i;
	char t;
	for(i = 0;mesg[i] != '\0';i++){
		if(mesg[i] >= 'a' && mesg[i] <= 'z'){
			t = 'z';
			if (mesg[i] - key < 'a')
				t = t - (mesg[i] - key -'a');
			else
				t = mesg[i] - key;
		}
		else if (mesg[i] >= 'A' && mesg[i] <= 'Z'){
			t = 'Z';
			if (mesg[i] - key < 'A')
				t = t - (mesg[i] - key -'A');
			else
				t = mesg[i] - key;
		}
		else
			t = mesg[i] - key;
		mesg[i] = t;
	}
	return ;
}

int main(){
	int key;
	char mesg[20] ,code[20];
	printf("Enter a message to encrypt it:");
	gets(mesg);
	printf("Enter the key to use:");
	scanf("%d",&key);
	encrypt(key,mesg);
	printf("The encode message is :");
	puts(mesg);
	printf("Enter any message to be decrypted:\n");
	gets(code);
	printf("Enter the key to decrypt the message:");
	scanf("%d",&key);
	decrypt(key,code);
	printf("The decoded message is:");
	puts(code);
	printf("\n");
	return 0;
}

