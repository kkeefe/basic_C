#include <fstream>

{

  ofstream outfile;

  outfile.open("outfile.txt", std::ios::app);
  
  h1 = new TH1I("h1", "Random Value", 2, -0.5, 1.5);

  //set dimensions of iteration
  const int dim = 100;
  
  cout << "text matrix generation" << endl;

  for(int j = 0; j < dim; j++){

    for(int i = 0; i < dim; i++){

    int rando = gRandom->Integer(2);
    
    //fill the histogram, check to ensure random
    h1->Fill(rando);

    //separate entries by tab
    outfile << rando << "\t";
    
      }
    //change line after each element j
    outfile << "\n";
  }


  //draw the histogram
  h1->SetMinimum(0);
  h1->Draw();

  outfile.close();
  
}
