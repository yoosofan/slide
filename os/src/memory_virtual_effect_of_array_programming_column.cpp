void work_with_array_column_by_column(void){
  double xa[1000][1000];
  int i,j;
  for(j=0;j<1000;j++)
    for(i=0;i<1000;i++)
      xa[i][j]=i*1000+j;
}
