void work_with_array_row_by_row(void){
  double xa[1000][1000];
  int i,j;
  for(i=0;i<1000;i++)
    for(j=0;j<1000;j++)
      xa[i][j]=i*1000+j;
}
