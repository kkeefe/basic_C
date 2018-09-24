{

  cout << "working.." << endl;
  //get the ntuple you want
  TFile* f = new TFile("Analysis.root", "title");
  TNtuple* ntup = (TNtuple*)f->Get("Ntuple3");

  auto long1 = ntup->GetBranch("fX_pos")->GetEntries();
  cout << "\nx entries: \t" << long1;

  auto long2 = ntup->GetBranch("fY_pos")->GetEntries();
  cout << "\ny entries: \t" << long2;

  TCanvas* c1 = new TCanvas("c1", "  ");
  ntup->SetMarkerStyle(20);
  ntup->SetMarkerColor(4);
  ntup->SetMarkerSize(1);
  ntup->Draw("fY_pos:fX_pos");
  
}
