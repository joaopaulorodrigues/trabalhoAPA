void selection_sort(int vetor[], int n){
   int i, j, min, loc, temp;
   for(i=0;i<n-1;i++)
   {
        min=vetor[i];
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(min>vetor[j])
            {
                min=vetor[j];
                loc=j;
            }
        }

        temp=vetor[i];
        vetor[i]=vetor[loc];
        vetor[loc]=temp;
    }

}

void selection_sort_desc(int vetor[], int n){
   int i, j, min, loc, temp;
   for(i=0;i<n-1;i++)
   {
        min=vetor[i];
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(min>vetor[j])
            {
                min=vetor[j];
                loc=j;
            }
        }

        temp=vetor[i];
        vetor[i]=vetor[loc];
        vetor[loc]=temp;
    }

}

void selection_sort_tax(int peso[], int valor[], int n){
   int i, j, loc, temp;
   float min;
   for(i=0;i<n-1;i++)
   {
        min= valor[i]/(float)peso[i];
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(min < valor[j]/(float)peso[j])
            {
                min = valor[j]/(float)peso[j];
                loc=j;
            }
        }

        temp=valor[i];
        valor[i]=valor[loc];
        valor[loc]=temp;

        temp=peso[i];
        peso[i]=peso[loc];
        peso[loc]=temp;
    }

}

