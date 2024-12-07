typedef struct object { 
	int a;	
	int b;
	char arr[6];
} OBJ;

int main(int argc, char const *argv[])
{	
	OBJ o = {10,10,{0}};

	OBJ *ptr = &o;


	return 0;
}