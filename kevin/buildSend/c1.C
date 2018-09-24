void c1()
{
//=========Macro generated from canvas: c1/c1
//=========  (Fri Jun  1 11:11:11 2018) by ROOT version 6.12/06
   TCanvas *c1 = new TCanvas("c1", "c1",10,67,757,532);
   gStyle->SetOptFit(1);
   c1->ToggleEventStatus();
   c1->Range(-4.930341,-2299.386,54.6517,25602.21);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   Double_t Graph0_fx1[12] = {
   5,
   10,
   14.14214,
   15.6205,
   18.02776,
   18.02776,
   22.36068,
   31.62278,
   31.62278,
   40,
   43.20494,
   44.72136};
   Double_t Graph0_fy1[12] = {
   2350.88,
   4974.5,
   7313.44,
   8131.06,
   9423.5,
   9423.5,
   11220.68,
   17716.42,
   17716.42,
   20402.74,
   20951.94,
   20613.66};
   TGraph *graph = new TGraph(12,Graph0_fx1,Graph0_fy1);
   graph->SetName("Graph0");
   graph->SetTitle("Cerenkov Photons Generated; Net Path Length in cm; Photon Count average from 50 trials");
   graph->SetFillStyle(1000);
   graph->SetLineColor(4);
   graph->SetMarkerStyle(21);
   
   TH1F *Graph_Graph_Graph11 = new TH1F("Graph_Graph_Graph11","Cerenkov Photons Generated",100,1.027864,48.6935);
   Graph_Graph_Graph11->SetMinimum(490.774);
   Graph_Graph_Graph11->SetMaximum(22812.05);
   Graph_Graph_Graph11->SetDirectory(0);
   Graph_Graph_Graph11->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph11->SetLineColor(ci);
   Graph_Graph_Graph11->GetXaxis()->SetTitle(" Net Path Length in cm");
   Graph_Graph_Graph11->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph11->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph11->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph11->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph11->GetYaxis()->SetTitle(" Photon Count average from 50 trials");
   Graph_Graph_Graph11->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph11->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph11->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph11->GetYaxis()->SetTitleOffset(0);
   Graph_Graph_Graph11->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph11->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph11->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph11->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph11->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph11);
   
   
   TF1 *f2 = new TF1("f","[0]*x+[1]",1.027864,48.6935, TF1::EAddToList::kNo);
   f2->SetFillColor(19);
   f2->SetFillStyle(0);
   f2->SetLineColor(2);
   f2->SetLineWidth(2);
   f2->SetChisquare(1.039647e+07);
   f2->SetNDF(10);
   f2->GetXaxis()->SetLabelFont(42);
   f2->GetXaxis()->SetLabelSize(0.035);
   f2->GetXaxis()->SetTitleSize(0.035);
   f2->GetXaxis()->SetTitleFont(42);
   f2->GetYaxis()->SetLabelFont(42);
   f2->GetYaxis()->SetLabelSize(0.035);
   f2->GetYaxis()->SetTitleSize(0.035);
   f2->GetYaxis()->SetTitleOffset(0);
   f2->GetYaxis()->SetTitleFont(42);
   f2->SetParameter(0,488.9725);
   f2->SetParError(0,22.99902);
   f2->SetParLimits(0,0,0);
   f2->SetParameter(1,525.7786);
   f2->SetParError(1,636.3178);
   f2->SetParLimits(1,0,0);
   f2->SetParent(graph);
   graph->GetListOfFunctions()->Add(f2);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 1.04e+07 / 10");
   ptstats_LaTex = ptstats->AddText("p0       =   489 #pm    23 ");
   ptstats_LaTex = ptstats->AddText("p1       = 525.8 #pm 636.3 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   graph->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(graph->GetListOfFunctions());
   graph->Draw("ap");
   
   TPaveText *pt = new TPaveText(0.248596,0.94,0.751404,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("Cerenkov Photons Generated");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
