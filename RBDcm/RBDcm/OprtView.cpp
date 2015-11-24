/**********************************************************************************
  Copyright @ Robin 2015-2025
  File name:  OprtView.cpp
  Author: Robin   Version: V1.0   Date:2015.11.05 
  Description:  operate form interface class
  Others:         
***********************************************************************************/
#include "stdafx.h"
#include "RBDcm.h"
#include "OprtView.h"

//define Command code of operations
const int  HIST     =		0;
const int  CUT      =		1;
const int  RST      =		2;
const int  MASK     =		3;
const int  MEDIAN   =		4;
const int  DRAWHIST =		5;
const int  ENTROPY  =		6;
const int  OSTU     =		7;
const int  ENHENCE  =		8;
const int  SRCIMG   =		9;
const int  LUNG     =		10;
const int  VIDEO    =		11; 
const int  PLAY     =		12; 
const int  LAST     =		13;
const int  NEXT     =		14;
const int  MEAN     =		15; 
const int  MOM      =		16;
const int LOADXML   =       17;


// COprtView
IMPLEMENT_DYNCREATE(COprtView, CFormView)

COprtView::COprtView()
	: CFormView(COprtView::IDD)
	, m_nSUM(0)
	, m_nCurrent(0)
{
}

COprtView::~COprtView()
{
}

/***************************************************************************************
Function: �ؼ�����ֵ�������ֵ����ֵת��
Input:    CDataExchange��ָ��
Output:  void
Description: MFC�ڲ�����ת������
Return:   void
Others:   NULL
***************************************************************************************/
void COprtView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_RST, m_reset);
	DDX_Control(pDX, IDC_BTN_DRAWHIST, m_btnHist);
	DDX_Control(pDX, IDC_BTN_HIST, m_btnEnhance);
	DDX_Control(pDX, IDC_BTN_CUT, m_btnCut);
	DDX_Control(pDX, IDC_BTN_MASK, m_btnMask);
	DDX_Control(pDX, IDC_BTN_MEDIAN, m_btnMed);
	DDX_Control(pDX, IDC_BTN_ENTROPY, m_btnEntropy);
	DDX_Control(pDX, IDC_BTN_OSTU, m_btnOSTU);
	DDX_Control(pDX, IDC_BTN_HENCE, m_btnHence);
	DDX_Control(pDX, IDC_BTN_SRCIMG, m_btnSrc);
	DDX_Control(pDX, IDC_BTN_LUNG3, m_btnLung);
	DDX_Control(pDX, IDC_BTN_VIDEO, m_btnCam);
	DDX_Control(pDX, IDC_BTN_PLAY, m_btnPlay);
	DDX_Text(pDX, IDC_EDIT_SUM, m_nSUM);
	DDX_Text(pDX, IDC_EDIT_CURRENT, m_nCurrent);
	DDX_Control(pDX, IDC_BTN_LAST, m_btnLast);
	DDX_Control(pDX, IDC_BTN_NEXT, m_btnNext);
	DDX_Control(pDX, IDC_BTN_MEAN, m_btnMean);
	DDX_Control(pDX, IDC_BTN_MOM, m_btnMoM);
	DDX_Control(pDX, IDC_BTN_LOADXML, m_btnLoadXML);
}

BEGIN_MESSAGE_MAP(COprtView, CFormView)
	ON_BN_CLICKED(IDC_BTN_HIST, &COprtView::OnBnClickedBtnHist)
	ON_BN_CLICKED(IDC_BTN_CUT, &COprtView::OnBnClickedBtnCut)
	ON_BN_CLICKED(IDC_BTN_RST, &COprtView::OnBnClickedBtnRst)
	ON_BN_CLICKED(IDC_BTN_MASK, &COprtView::OnBnClickedBtnMask)
	ON_BN_CLICKED(IDC_BTN_MEDIAN, &COprtView::OnBnClickedBtnMedian)
	ON_BN_CLICKED(IDC_BTN_DRAWHIST, &COprtView::OnBnClickedBtnDrawhist)
	ON_BN_CLICKED(IDC_BTN_ENTROPY, &COprtView::OnBnClickedBtnEntropy)
	ON_BN_CLICKED(IDC_BTN_OSTU, &COprtView::OnBnClickedBtnOstu)
	ON_BN_CLICKED(IDC_BTN_HENCE, &COprtView::OnBnClickedBtnHence)
	ON_BN_CLICKED(IDC_BTN_SRCIMG, &COprtView::OnBnClickedBtnSrcimg)
	ON_BN_CLICKED(IDC_BTN_LUNG3, &COprtView::OnBnClickedBtnLung)
	ON_BN_CLICKED(IDC_BTN_VIDEO, &COprtView::OnBnClickedBtnVideo)
	ON_BN_CLICKED(IDC_BTN_PLAY, &COprtView::OnBnClickedBtnPlay)
	ON_BN_CLICKED(IDC_BTN_LAST, &COprtView::OnBnClickedBtnLast)
	ON_BN_CLICKED(IDC_BTN_NEXT, &COprtView::OnBnClickedBtnNext)
	ON_BN_CLICKED(IDC_BTN_MEAN, &COprtView::OnBnClickedBtnMean)
	ON_BN_CLICKED(IDC_BTN_MOM, &COprtView::OnBnClickedBtnMom)
	ON_BN_CLICKED(IDC_BTN_LOADXML, &COprtView::OnBnClickedBtnLoadxml)
	ON_COMMAND(IDM_SERILE, &COprtView::OnSerile)
	ON_COMMAND(ID_FILE_OPEN, &COprtView::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, &COprtView::OnFileSave)
END_MESSAGE_MAP()


// COprtView ���
#ifdef _DEBUG
void COprtView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void COprtView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


/***************************************************************************************
Function: �����ʼ��
Input:    NULL
Output:  void
Description: ����Button����ʾIcon
Return:   void
Others:   NULL
***************************************************************************************/
void COprtView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	//m_pRDBView = (CRBDcmView*)(((CMainFrame*)AfxGetMainWnd())->m_splt.GetPane(0, 1));
	//m_pDoc = m_pRDBView->GetDocument();
	m_pMainFrm = (CMainFrame*)AfxGetMainWnd();
	m_reset.SetIcon(IDI_RESET);             //��ԭ
	m_btnHist.SetIcon(IDI_HIST);            //ֱ��ͼ
	m_btnEnhance.SetIcon(IDI_ENHANCE);      //ȫ��ֱ��ͼ��ǿ
	m_btnCut.SetIcon(IDI_CUT);              //�ֶ���ֵ
	m_btnMask.SetIcon(IDI_MASK);            //Mask
	m_btnMed.SetIcon(IDI_MED);              //��ֵ�˲�
	m_btnEntropy.SetIcon(IDI_ENTROPY);      //�طָ�
	m_btnOSTU.SetIcon(IDI_OSTU);            //OSTU�ָ�
	m_btnHence.SetIcon(IDI_HENCE);          //�߼���ǿ
	m_btnSrc.SetIcon(IDI_SRC);              //�鿴ԭͼ
	m_btnLung.SetIcon(IDI_LUNG);            //�ָ��ʵ��
	m_btnCam.SetIcon(IDI_ENHANCE);          //����ͷ
	m_btnPlay.SetIcon(IDI_PLAY);			//���в���
	m_btnLast.SetIcon(IDI_LAST);			//��һ��
	m_btnNext.SetIcon(IDI_NEXT);			//��һ��
	m_btnMean.SetIcon(IDI_MEAN);			//��ֵ����
	m_btnMoM.SetIcon(IDI_OSTU);				//
	m_btnLoadXML.SetIcon(IDI_OSTU);			//
}



/***************************************************************************************
Function: ���ݰ��°���ִ����Ӧ����Ϣִ����Ӧ�Ĳ���
Input:    NULL
Output:  void
Description: ��Ӧ��Ϣ�ۺϵ�һ��Ϊ�˴���ļ�
Return:   void
Others:   NULL
***************************************************************************************/
void COprtView::Executive(int msg)
{
	CRBDcmDoc* m_pDoc = ((CMainFrame*)AfxGetMainWnd())->m_pRBView->GetDocument();
	if (m_pDoc->m_srcImage.empty())          //��ʾ������û��ͼ������ʱ�Ͳ��ô�����ֱ�ӷ���
	{
		return;
	}
	switch (msg)
	{
	case HIST:
		m_pDoc->Hist();
		break;
	case CUT:
		m_pDoc->Cut();
		break;
	case RST:
		m_pDoc->Rst();
		break;
	case MASK:
		m_pDoc->Mask();
		break;
	case MEDIAN:
		m_pDoc->Median();
		break;
	case DRAWHIST:
		m_pDoc->DrawHist();
		break;
	case ENTROPY:
		m_pDoc->Entropy();
		break;
	case OSTU:
		m_pDoc->Ostu();
		break;
	case ENHENCE:
		m_pDoc->Enhance();
		break;
	case SRCIMG:
		m_pDoc->SrcImg();
		break;
	case LUNG:
		m_pDoc->SegLung();
		break;
	case VIDEO:
		m_pDoc->Video();
		break;
	case PLAY:
		m_pDoc->PlaySerile();
		break;
	case LAST:
		m_pDoc->Last();
		break;
	case NEXT:
		m_pDoc->Next();
		break;
	case MEAN:
		m_pDoc->Mean();
		break;
	case MOM:
		m_pDoc->MoM();
		break;
	case LOADXML:
		m_pDoc->LoadXml();
	default:
		break;
	}
	m_pDoc->ShowImg();
	(m_pMainFrm->m_pRBView)->Invalidate(FALSE);
}


//Histogram Equalization
void COprtView::OnBnClickedBtnHist()
{
	Executive(HIST);
}

//threshold segmentation
void COprtView::OnBnClickedBtnCut()
{
	Executive(CUT);
}

//Image data reset
void COprtView::OnBnClickedBtnRst()
{
	Executive(RST);
}



//median filter
void COprtView::OnBnClickedBtnMedian()
{
	Executive(MEDIAN);
}


//Max entropy segment
void COprtView::OnBnClickedBtnEntropy()
{
	Executive(ENTROPY);
}

//Hence Image
void COprtView::OnBnClickedBtnHence()
{
	Executive(ENHENCE);
}

//Show source image 
void COprtView::OnBnClickedBtnSrcimg()
{
	Executive(SRCIMG);
}


//play image serials
void COprtView::OnBnClickedBtnPlay()
{
	Executive(PLAY);
}


void COprtView::OnBnClickedBtnMean()
{
	Executive(MEAN);
}


void COprtView::SetSum(int num)
{
	m_nSUM = num;
	UpdateData(FALSE);
}


void COprtView::SetCurrent(int num)
{
	m_nCurrent = num;
	UpdateData(FALSE);
}


void COprtView::OnSerile()
{
	CFileDialog dlg(TRUE);								//�ļ��򿪶Ի���
	CFileFind ff;										//�ļ�������
	CStringArray dcmPathstr;							//�ļ�·��+�ļ����б� dcm�ļ�
	dlg.m_ofn.lpstrTitle = "��ͼ������";				//ָ�����ļ��Ի�������
	dlg.m_ofn.lpstrFilter = "Dcm Files(*.dcm)\0*.dcm\0All Files(*.*)\0*.*\0\0";  //�ļ�������

	if (IDCANCEL == dlg.DoModal())						//�����ļ��򿪶Ի���ѡ��ȡ����ֱ�ӷ���
		return;

	CString strFileName = dlg.GetPathName();			//��ȡ�ļ�·��+�ļ���
	int end = strFileName.ReverseFind('\\');			//�������
	CString strFilePath = strFileName.Left(end);		//ȥ�������ļ����õ��ļ�Ŀ¼

	if(!ff.FindFile(strFilePath + "\\*.dcm"))			//����Ŀ¼���Ƿ����dcm�ļ������������˳�
		return;

	while(ff.FindNextFile())							//����dcm�ļ��������ļ�����·������dcmPathstr
		dcmPathstr.Add(strFilePath + "\\" + ff.GetFileName());

	m_ImgSerial.Clear();								//��������ǰ�����
	CString strXml = NULL;								//�ļ�·��
	for (int i=0; i<dcmPathstr.GetSize(); ++i)		
	{
		strFileName = dcmPathstr.GetAt(i);				//��������ȡ���ļ�·��
		m_ImgSerial.LoadDcm(strFileName);				//����Dcm�ļ�
	}
	SetSum(m_ImgSerial.GetImageNum());					//��ʾ��ǰͼ������
	SetCurrent(m_ImgSerial.GetCurrentNum());			//��ʾ��ǰͼ�����
	sOneImg info = m_ImgSerial.GetCurrentMatImg();		//ȡ�õ�ǰͼ��
	(m_pMainFrm->m_pRBView)->SetImgData(info);			//��ͼ�����õ�CRBDcm����
	//(((CMainFrame*)AfxGetMainWnd())->m_pRBView)->SetImgData(info);	//��ͼ�����õ�CRBDcm����
}


void COprtView::OnFileOpen()
{
	CFileDialog dlg(TRUE);								//�ļ��򿪶Ի���
	dlg.m_ofn.lpstrTitle = "��ͼ������";				//ָ�����ļ��Ի�������
	//�ļ�������
	dlg.m_ofn.lpstrFilter = "Dcm Files(*.dcm)\0*.dcm\0All Files(*.*)\0*.*\0\0";		
	if (IDCANCEL == dlg.DoModal())						//�����ļ��򿪶Ի���ѡ��ȡ����ֱ�ӷ���
		return;
	CString strFileName = dlg.GetPathName();			//��ȡ�ļ�·��+�ļ���
	m_ImgSerial.Clear();								//���ԭ������
	m_ImgSerial.LoadDcm(strFileName);					//��������
	sOneImg info = m_ImgSerial.GetCurrentMatImg();		//�����е�ǰͼ��
	(m_pMainFrm->m_pRBView)->SetImgData(info);			//���õ�ǰͼ��
	//(((CMainFrame*)AfxGetMainWnd())->m_pRBView)->SetImgData(info); //���õ�ǰͼ��
}


void COprtView::OnBnClickedBtnLoadxml()
{
	CFileDialog dlg(TRUE);								//�ļ��򿪶Ի���
	dlg.m_ofn.lpstrTitle = "��Xml�ļ�";				//ָ�����ļ��Ի�������
	//�ļ�������
	dlg.m_ofn.lpstrFilter = "xml Files(*.xml)\0*.xml\0All Files(*.*)\0*.*\0\0";  
	if (IDCANCEL == dlg.DoModal())						//�����ļ��򿪶Ի���ѡ��ȡ����ֱ�ӷ���
		return;
	CString strFileName = dlg.GetPathName();			//��ȡ�ļ�·��+�ļ���
	m_ImgSerial.LoadXml(strFileName);					//����xml�ļ�
	sOneImg info = m_ImgSerial.GetCurrentMatImg();
	//�����һ�����洫���ڵ���Ϣ
	(m_pMainFrm->m_pInfoView)->SetImgData(info);
	//(((CMainFrame*)AfxGetMainWnd())->m_pInfoView)->SetImgData(info);  
}


//OSTU segment
void COprtView::OnBnClickedBtnOstu()
{
	CSegmentOperat seg;
	cv::Mat m_dstImage = seg.OstuSeg(m_ImgSerial.GetCurrentMatImg().pixle.clone()).clone();
	sOneImg info = m_ImgSerial.GetCurrentMatImg();
	info.pixle = m_dstImage.clone();
	(m_pMainFrm->m_pSegView)->SetImgData(info);
	//(((CMainFrame*)AfxGetMainWnd())->m_pSegView)->SetImgData(info);
}


//Get real area of Lung
void COprtView::OnBnClickedBtnLung()
{
	//��ʵ�ʵķָ���ڷָ�������
	(m_pMainFrm->m_pSegView)->SegRealLung(m_ImgSerial.GetCurrentMatImg().pixle.clone());
	//(((CMainFrame*)AfxGetMainWnd())->m_pSegView)->SegRealLung(m_ImgSerial.GetCurrentMatImg().pixle.clone());
}


//�����ָ�
void COprtView::OnBnClickedBtnMom()
{
	sOneImg img;	//��ʵ�ʴ����е�ͼ��
	(m_pMainFrm->m_pSegView)->GetSegRealLungs(img);
	(m_pMainFrm->m_pClassier)->SegNodules(img);
	//(((CMainFrame*)AfxGetMainWnd())->m_pSegView)->GetSegRealLungs(img);
	//(((CMainFrame*)AfxGetMainWnd())->m_pClassier)->SegNodules(img);
}


void COprtView::OnBnClickedBtnLast()
{
	sOneImg img = m_ImgSerial.LastMatImg();
	(m_pMainFrm->m_pRBView)->SetImgData(img);
	(m_pMainFrm->m_pInfoView)->SetImgData(img);
	SetCurrent(m_ImgSerial.GetCurrentNum());
}


void COprtView::OnBnClickedBtnNext()
{
	sOneImg img = m_ImgSerial.NextMatImg();
	(m_pMainFrm->m_pRBView)->SetImgData(img);
	if (img.SingleNodules.vcNodulePoint.size() > 0)
		(m_pMainFrm->m_pInfoView)->SetImgData(img);
	else
		(m_pMainFrm->m_pInfoView)->DeleteAll();
	SetCurrent(m_ImgSerial.GetCurrentNum());
}


/***************************************************************************************
Function: ����ͼ��ֱ��ͼ
Input:    void
Output:   
Description:  ����ͼ��ֱ��ͼ�����ƽ�������Ի����ʾ, ���Ƶ��ǵ�ǰ��ʾ�������showImageͼ��
Return:   void
Others:   NULL
***************************************************************************************/
void COprtView::OnBnClickedBtnDrawhist()
{
	CDrawHistDlg dlg;
	dlg.SetHistValue(m_ImgSerial.GetCurrentMatImg().pixle.clone());
	dlg.DoModal();
}


/***************************************************************************************
Function: ͼ����Ĥ
Input:    void
Output:   ʹ�ýṹԪ�ض�ͼ�������Ĥ��������Ĥ��������opencv
Description: 
Return:   void
Others:   NULL
***************************************************************************************/
void COprtView::OnBnClickedBtnMask()
{
	CMaskSetDlg dlg;
	if (IDCANCEL == dlg.DoModal())
		return;
	cv::Mat kernal;									//�����任��
	cv::Mat dst;									//Ŀ��ͼ��
	if (dlg.m_mask.weight != 0)
	{
		double tmp = (double)dlg.m_mask.weight;
		kernal = (Mat_<double>(3, 3) <<
			dlg.m_mask.mk[0][0]/tmp, dlg.m_mask.mk[0][1]/tmp, dlg.m_mask.mk[0][2]/tmp,
			dlg.m_mask.mk[1][0]/tmp, dlg.m_mask.mk[1][1]/tmp, dlg.m_mask.mk[1][2]/tmp,
			dlg.m_mask.mk[2][0]/tmp, dlg.m_mask.mk[2][1]/tmp, dlg.m_mask.mk[2][2]/tmp);
	}
	else
	{
		kernal = (Mat_<char>(3, 3) <<
			dlg.m_mask.mk[0][0], dlg.m_mask.mk[0][1], dlg.m_mask.mk[0][2],
			dlg.m_mask.mk[1][0], dlg.m_mask.mk[1][1], dlg.m_mask.mk[1][2],
			dlg.m_mask.mk[2][0], dlg.m_mask.mk[2][1], dlg.m_mask.mk[2][2]);
	}
	filter2D(m_ImgSerial.GetCurrentMatImg().pixle.clone(), dst, 8, kernal);
	//(m_pMainFrm->m_pSegView)->SegRealLung(m_ImgSerial.GetCurrentMatImg().pixle.clone());
}


void COprtView::OnFileSave()
{
}


//����ͷ��������
void COprtView::OnBnClickedBtnVideo()
{
	cv::VideoCapture cam(0);
	if(!cam.isOpened())
		return;
	cv::Mat frame;
	cv::Mat gary;
	bool stop = false;
	namedWindow("cam", 1);
	while (!stop)
	{
		cam>>frame;
		//��ʱ���ȡ�������ǿյ�
		if (frame.empty())
		{
			continue;
		}
		cvtColor(frame, gary, CV_BGR2GRAY);
		threshold(gary, gary, 100, 255, 0);  //
		imshow("cam", frame);
		if (waitKey(30) >= 0)
		{
			stop = true;
		}
	}
	HWND hWnd = ::FindWindow(NULL,"cam");
	::CloseWindow(hWnd);
	::DestroyWindow(hWnd);
	cam.release();
}