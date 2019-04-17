#include <fstream>

{

  ofstream outfile;

  outfile.open("outfile500.txt");
  
  h1 = new TH1I("h1", "Random Value", 2, -0.5, 1.5);

  //set dimensions of iteration
  const int dim = 500;

  int a[dim][dim];
  
  cout << "text matrix generation" << endl;

  for(int j = 0; j < dim; j++){

    for(int i = 0; i < dim; i++){

    int rando = gRandom->Integer(2);
    
    //fill the histogram, check to ensure random
    h1->Fill(rando);

    //separate entries by tab
    outfile << rando << "\t";

    a[j][i] = rando;

    std::cout << a[j][i] << "\t";
    
      }
    //change line after each element j
    outfile << "\n";
    std::cout << "\n";
  }

  //row iteration
  for(int i = 0; i < dim; ++i){
    //column iteration
    for(int j = 0; j < dim; ++j){
      //find the horrizontal matches
      if(a[i][j] == a[i+1][j]){
	cout << "horrizontal match at " << i << " row " << j << " column " << endl;
      }
      //find vertical matches
      if(a[i][j] == a[i][j+1]){
	cout << "verical match at " << i << " row " << j << " column " << endl;
      }
    }
  }
    

  //draw the histogram, checks for distribution of elements
  h1->SetMinimum(0);
  h1->Draw();

  //make sure to close the file
  outfile.close();
  
}
