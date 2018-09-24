//this is an intro the graphing macro

{
  g = new TGraph("MuonAngleData.txt");
  g->SetMarkerStyle(21);
  g->SetLineColor(kBlue);
  g->SetTitle("Cerenkov Photons Generated; Net Path Length in cm; Photon Count average from 50 trials");

  //goal is to find a guessed fit function!
  //this fits a sine function using the three below parameters to adjust the 'guessed' fit
  //note that each [n] indicates the nth parameter.
  f = new TF1("f", "[0]*x+[1]",0, 45);
  f->SetParNames("Amplitude Factor" , "Vertical Shift" , "Translanslation error");

  //create a guess of each of the values
  f->SetParameters(490,0);
  f->SetMinimum(0);
  
  g->Fit(f);

  g->Draw("AP");
  
}
