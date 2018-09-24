{
  c1 = new TCanvas("c1", "ntuples", 600, 600);
  c1->SetGrid();

  gStyle->SetMarkerSize(10);
  gStyle->SetMarkerColor(5);
  gStyle->SetOptStat(111111);

  TFile* f = new TFile("pmma_ps_xdir_only.root", "pmma and ps");
  //get the ntuple you want

  TTree* ttree = (TTree*)f->Get("Ntuple3");
  cout << "Working.. "  << endl;

  ttree->Draw("fX_pos:fY_pos","", "col");
}
