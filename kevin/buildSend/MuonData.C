//this is an intro the graphing macro

{

  g = new TGraph("MuonCerenkovGeVData");
  g->SetMarkerStyle(21);
  g->SetLineColor(kBlue);
  g->SetTitle("Cerenkov Photons Generated; GeV; Photon Count");


  g->Draw("APC");
  
}
