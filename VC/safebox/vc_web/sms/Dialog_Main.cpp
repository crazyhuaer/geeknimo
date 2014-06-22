// Dialog_Main.cpp : implementation file
//

#include "stdafx.h"
#include "sms.h"
#include "Dialog_Main.h"
#include "smsDlg.h"
#include "md5_password.h"
#include "Comm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialog_Main dialog


CDialog_Main::CDialog_Main(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_Main::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialog_Main)
	//}}AFX_DATA_INIT
}


void CDialog_Main::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialog_Main)
	DDX_Control(pDX, IDC_PERIOD_SEND, m_Period_Send);
	DDX_Control(pDX, IDC_START_SEND, m_Start_Send);
	DDX_Control(pDX, IDC_DATA_URL, m_Data_Url);
	DDX_Control(pDX, IDC_COM_NUMBER, m_Com_Number);
	DDX_Control(pDX, IDC_TEST_GPRS, m_test_gprs);
	DDX_Control(pDX, IDC_ON_OFF_TC35, m_Open_MSCOMM);
	DDX_Control(pDX, IDC_STATUS_INFORMATION, m_Status_Information);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialog_Main, CDialog)
	//{{AFX_MSG_MAP(CDialog_Main)
	ON_BN_CLICKED(IDC_ON_OFF_TC35, OnOnOffTc35)
	ON_BN_CLICKED(IDC_TEST_GPRS, OnTestGprs)
	ON_BN_CLICKED(IDC_START_SEND, OnStartSend)
	ON_WM_TIMER()
	ON_EN_KILLFOCUS(IDC_PERIOD_SEND, OnKillfocusPeriodSend)
	ON_EN_SETFOCUS(IDC_PERIOD_SEND, OnSetfocusPeriodSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialog_Main message handlers

void CDialog_Main::OnOnOffTc35() 
{
	CTime tmTime = CTime::GetCurrentTime ();

	((CSmsApp*)AfxGetApp())->m_Log.LogMessage("端口连接");
	// Get the parameter
	if (m_MSCOMM_Open)
	{
		::CloseComm();
		m_MSCOMM_Open = FALSE;

        m_Status_Information.SetSel(-1, -1);
        m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"串口已关闭\n");

		m_test_gprs.EnableWindow(FALSE);

		m_Start_Send.SetWindowText("启动定时发送");
		m_Start_Send.EnableWindow(FALSE);

		m_Open_MSCOMM.SetWindowText("打开TC35串口");
		m_test_gprs.EnableWindow(FALSE);
		((CSmsApp*)AfxGetApp())->m_Log.LogMessage("串口已关闭");
	}
	else
	{
		// Open the COMN
		int		nRate = 9600;
		CString	tmp ;
		CTime tmTime = CTime::GetCurrentTime ();

		m_Com_Number.GetWindowText(tmp);
		//AfxMessageBox(tmp);
		if (!::OpenComm(tmp, nRate))
		{
			m_Status_Information.SetSel(-1, -1);
			m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"串口打开异常，请尝试切换其他端口\n");
			m_test_gprs.EnableWindow(FALSE);
			
			m_Start_Send.SetWindowText("启动定时发送");
			m_Start_Send.EnableWindow(FALSE);
			
			m_Open_MSCOMM.SetWindowText("打开TC35串口");
			m_test_gprs.EnableWindow(FALSE);
			//AfxMessageBox("无法打开串口，请换其他端口或者检查是否连接正常");
			((CSmsApp*)AfxGetApp())->m_Log.LogMessage("串口打开异常，请尝试切换其他端口");
		}
		else
		{
			m_MSCOMM_Open = TRUE;
			m_Status_Information.SetSel(-1, -1);
			m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"串口打开成功\n");
			m_test_gprs.EnableWindow(TRUE);
			m_Open_MSCOMM.SetWindowText("关闭TC35串口");
			((CSmsApp*)AfxGetApp())->m_Log.LogMessage("串口打开成功");
		}
	}
}

void CDialog_Main::OnTestGprs() 
{
	extern CSmsApp theApp;
	
	CTime tmTime = CTime::GetCurrentTime ();

	if (!gsmInit())
	{

		m_Status_Information.SetSel(-1, -1);
		m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"TC35连接失败\n");

		m_Start_Send.SetWindowText("启动定时发送");
		m_Start_Send.EnableWindow(FALSE);

		theApp.m_Log.LogMessage("TC35连接失败");
	}
	else
	{
		m_Status_Information.SetSel(-1, -1);
		m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"TC35连接成功\n");

		m_Start_Send.SetWindowText("启动定时发送");
		m_Start_Send.EnableWindow(TRUE);

		theApp.m_Log.LogMessage("TC35连接成功");
	}
}

/************************************************************************/
/* Funtion is used to start timer 1.      
	re-click will close timer 1;                       
*/
/************************************************************************/
void CDialog_Main::OnStartSend() 
{
	// TODO: Add your control notification handler code here
	
	CTime tmTime = CTime::GetCurrentTime ();

	if (!gsmInit())
	{
		m_Status_Information.SetSel(-1, -1);
		m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"TC35连接失败\n");
		
		m_Start_Send.SetWindowText("启动定时发送");
		m_Start_Send.EnableWindow(FALSE);

		((CSmsApp*)AfxGetApp())->m_Log.LogMessage("TC35连接失败");
		return;
	}

	CString	strPeriod;
	m_Period_Send.GetWindowText(strPeriod);
	
	if (strPeriod == "" || atoi(strPeriod) <= 0 )
	{
		//AfxMessageBox("周期设置错错误，请设置大于0的周期");
		m_Status_Information.SetSel(-1, -1);
		m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"周期设置错误，请正确设置为大于0的数\n");
		((CSmsApp*)AfxGetApp())->m_Log.LogMessage("周期设置错误，请正确设置为大于0的数");
	} 
	else
	{
		m_Status_Timer = !m_Status_Timer;
		
		if (m_Status_Timer)
		{
			// 定时器1，定时1000ms
			
			m_Start_Send.SetWindowText("关闭定时发送");
			m_Status_Information.SetSel(-1, -1);
			m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"定时器已经启动，周期为"+strPeriod+"s一次\n");
			((CSmsApp*)AfxGetApp())->m_Log.LogMessage("定时器已经启动，周期为"+strPeriod+"s一次");
			{
				// This message is used to test.
				//CString	strSmsc = "13010888500";		//短信中心号码(请勿改动，这是深圳短信中心号码)
				//CString	strNumber = "13006661808";		//欲发送的短信号码
				//CString	strContent = "发送的中文内容";	//发送的内容
				
				// get the data from the sever
				// if the server response data is out of our control,will do nothing.
				// otherwise,send the message.
				// you need to get the strSmsc,strNumber,strContent.
				
				CString strSmsc = "",strNumber,strContent;	
				
				CTabCtrl *pDlg = (CTabCtrl *)GetParent();
				CSmsDlg *pSmsDlg = (CSmsDlg *)this->GetParent()->GetParent();
				
				// Get the data from server.
				CInternetSession m_session;
				CString strData;
				TCHAR	ch;
				CString	strRequestURL,strRequestData;
				
				CString	strUsername = pSmsDlg->m_Login_Tab.m_strUsername;
				CString strPassword = pSmsDlg->m_Login_Tab.m_strPassword;
				
				char* User_Password_Char=strPassword.GetBuffer(strPassword.GetLength());
				strPassword = MDString(User_Password_Char);
				
				m_Data_Url.GetWindowText(strRequestURL);
				strRequestURL.TrimLeft(); 
				strRequestURL.TrimRight();
				if (strRequestURL == "")
				{
					AfxMessageBox("请按照格式输入服务器地址");
					((CSmsApp*)AfxGetApp())->m_Log.LogMessage("没有输入服务器地址");
				}
				else if (strRequestURL.Left(7) == "http://" )
				{
					strRequestData = "?username="+ strUsername +"&password="+strPassword;

					((CSmsApp*)AfxGetApp())->m_Log.LogMessage("手机号码请求发送的服务器连接:"+strRequestURL+strRequestData);
					CHttpFile *pFile = (CHttpFile *) m_session.OpenURL(strRequestURL+strRequestData, 1, 
						INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
					
					while (pFile->Read(&ch, sizeof(TCHAR)))
					{
						strData += ch;
					}	
					
					CString* pStr;
					int iSubStrs;
					pStr = SplitString(strData, '#', iSubStrs);
					((CSmsApp*)AfxGetApp())->m_Log.LogMessage("服务器返回的数据为:"+strData);
					// if the substr just one.
					if (iSubStrs == 1)
					{
						// This Mean the server is not ok.
						// you need process it.
						//AfxMessageBox(strData); 
						KillTimer(1);
						m_Status_Information.SetSel(-1, -1);
						m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"定时器遇到意外情况被迫关闭\n");
						((CSmsApp*)AfxGetApp())->m_Log.LogMessage("定时器遇到意外情况被迫关闭");
						m_Start_Send.SetWindowText("启动定时发送");
					}
					else
					{   
						// Follow the format,i set the second parm is number,the third is content,the first is status.
						pStr[2].TrimRight("");
						
						// Send the message.
						SendTheMessage(strSmsc,pStr[1],pStr[2]);
						m_Status_Information.SetSel(-1, -1);
						m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"发送"+pStr[1]+":"+pStr[2]+"\n");
						((CSmsApp*)AfxGetApp())->m_Log.LogMessage("发送"+pStr[1]+":"+pStr[2]);
						delete []pStr;
					}		
					// Start the timer 1
					SetTimer(1,atoi(strPeriod)*1000,NULL);
				}
				else
				{
					AfxMessageBox("请使用http协议");
					((CSmsApp*)AfxGetApp())->m_Log.LogMessage("输入的协议不正确");
				}
			}
		} 
		else
		{
			KillTimer(1);
			m_Start_Send.SetWindowText("启动定时发送");
			m_Status_Information.SetSel(-1, -1);
			m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"定时器已经关闭\n");
			((CSmsApp*)AfxGetApp())->m_Log.LogMessage("定时器已经关闭");
		}
	}
}

void CDialog_Main::SendTheMessage(CString strSmsc,CString strNumber,CString strContent)
{
	SM_PARAM SmParam;

	memset(&SmParam, 0, sizeof(SM_PARAM));
	
	// set the default strSmsc
	strSmsc = "13010888500";

	// 去掉号码前的"+"
	if(strSmsc[0] == '+')  strSmsc = strSmsc.Mid(1);		//短信中心号码
	if(strNumber[0] == '+')  strNumber = strNumber.Mid(1);	//短信号码
	
	// 在号码前加"86"
	if(strSmsc.Left(2) != "86")  strSmsc = "86" + strSmsc;
	if(strNumber.Left(2) != "86")  strNumber = "86" + strNumber;

	// 填充短消息结构
	strcpy(SmParam.SCA, strSmsc);
	strcpy(SmParam.TPA, strNumber);
	strcpy(SmParam.TP_UD, strContent);		//短信内容
	SmParam.TP_PID = 0;
	SmParam.TP_DCS = GSM_UCS2;
	
	((CSmsApp*)AfxGetApp())->m_Log.LogMessage("正在发送短消息");
	// 发送短消息
	m_pSmsTraffic->PutSendMessage(&SmParam);

	char ans[128];
	ReadComm(ans, 128);

	int iPos = 0;
	CString	returnByte;
	returnByte.Format("%s",ans);

	//+CMGS:

	//m_Status_Information.ReplaceSel(returnByte+"\n");

	//查看是否发送成功，如果成功，则修改服务器数据的状态
	iPos = returnByte.Find("CMGS");

	m_Status_Information.SetSel(-1, -1);
	CTime tmTime = CTime::GetCurrentTime ();
	if (iPos == -1)
	{
		m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"发送失败\n");
		((CSmsApp*)AfxGetApp())->m_Log.LogMessage("发送失败");
    }
	else
	{
		m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"发送成功\n");
		((CSmsApp*)AfxGetApp())->m_Log.LogMessage("发送成功");

		//update server status
		// Get the data from server.
		CInternetSession m_session;
		CString strData;
		TCHAR	ch;
		CString	strRequestURL,strRequestData;
		
		CTabCtrl *pDlg = (CTabCtrl *)GetParent();
		CSmsDlg *pSmsDlg = (CSmsDlg *)this->GetParent()->GetParent();

		CString	strUsername = pSmsDlg->m_Login_Tab.m_strUsername;
		CString strPassword = pSmsDlg->m_Login_Tab.m_strPassword;
		
		char* User_Password_Char=strPassword.GetBuffer(strPassword.GetLength());
		strPassword = MDString(User_Password_Char);
		
		//strRequestURL = "http://192.168.1.200/projecttest/phone/index.php";
		m_Data_Url.GetWindowText(strRequestURL);
		strRequestURL.TrimLeft(); 
		strRequestURL.TrimRight();
		if (strRequestURL == "")
		{
			AfxMessageBox("请按照格式输入服务器地址");
			((CSmsApp*)AfxGetApp())->m_Log.LogMessage("没有输入服务器地址");
		}
		else if (strRequestURL.Left(7) == "http://" )
		{
			strRequestData = "?username="+ strUsername +"&password="+strPassword;
			((CSmsApp*)AfxGetApp())->m_Log.LogMessage("反馈服务器url:"+strRequestURL+strRequestData);

			CHttpFile *pFile = (CHttpFile *) m_session.OpenURL(strRequestURL+strRequestData, 1, 
										INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
			
			while (pFile->Read(&ch, sizeof(TCHAR)))
			{
				strData += ch;
			}	
			m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"服务器返回的是"+strData+"\n");
			((CSmsApp*)AfxGetApp())->m_Log.LogMessage("服务器返回的是"+strData);
		}
		else
		{
			AfxMessageBox("请使用http协议");
			((CSmsApp*)AfxGetApp())->m_Log.LogMessage("输入的协议不正确");
		}
	}
}

void CDialog_Main::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nIDEvent)
	{
	case 1:
		//做该做的事情
		{
			// This message is used to test.
			//CString	strSmsc = "13010888500";		//短信中心号码(请勿改动，这是深圳短信中心号码)
			//CString	strNumber = "13006661808";		//欲发送的短信号码
			//CString	strContent = "发送的中文内容";	//发送的内容
			
			// get the data from the sever
			// if the server response data is out of our control,will do nothing.
			// otherwise,send the message.
			// you need to get the strSmsc,strNumber,strContent.

			CString strSmsc = "",strNumber,strContent;	

			CTabCtrl *pDlg = (CTabCtrl *)GetParent();
			CSmsDlg *pSmsDlg = (CSmsDlg *)this->GetParent()->GetParent();
			
			// Get the data from server.
			CInternetSession m_session;
			CString strData;
			TCHAR	ch;
			CString	strRequestURL,strRequestData;
			
			CString	strUsername = pSmsDlg->m_Login_Tab.m_strUsername;
			CString strPassword = pSmsDlg->m_Login_Tab.m_strPassword;

			char* User_Password_Char=strPassword.GetBuffer(strPassword.GetLength());
		    strPassword = MDString(User_Password_Char);
	
			//strRequestURL = "http://192.168.1.200/projecttest/phone/index.php";
			m_Data_Url.GetWindowText(strRequestURL);
			strRequestURL.TrimLeft(); 
			strRequestURL.TrimRight();
			if (strRequestURL == "")
			{
				AfxMessageBox("请按照格式输入服务器地址");
				((CSmsApp*)AfxGetApp())->m_Log.LogMessage("没有输入服务器地址");
			}
			else if (strRequestURL.Left(7) == "http://" )
			{
				strRequestData = "?username="+ strUsername +"&password="+strPassword;
				
				((CSmsApp*)AfxGetApp())->m_Log.LogMessage("号码请求url连接为:"+strRequestURL+strRequestData);

				CHttpFile *pFile = (CHttpFile *) m_session.OpenURL(strRequestURL+strRequestData,1, 
					INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
				
				while (pFile->Read(&ch, sizeof(TCHAR)))
				{
					strData += ch;
				}	
				
				//AfxMessageBox(strData);
				((CSmsApp*)AfxGetApp())->m_Log.LogMessage("服务器反馈回来的数据为:"+strData);

				CString* pStr;
				int iSubStrs;
				pStr = SplitString(strData, '#', iSubStrs);
				CTime tmTime = CTime::GetCurrentTime ();
				// if the substr just one.
				if (iSubStrs == 1)
				{
					// This Mean the server is not ok.
					// you need process it.
					//AfxMessageBox(strData); 
					KillTimer(1);
					m_Status_Information.SetSel(-1, -1);
					m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"定时器遇到意外情况被迫关闭\n");
					m_Start_Send.SetWindowText("启动定时发送");

					((CSmsApp*)AfxGetApp())->m_Log.LogMessage("定时器遇到意外情况被迫关闭");
				}
				else
				{   
					// Follow the format,i set the second parm is number,the third is content,the first is status.
					pStr[2].TrimRight("");

					// Send the message.
					SendTheMessage(strSmsc,pStr[1],pStr[2]);
					m_Status_Information.SetSel(-1, -1);
					m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"发送"+pStr[1]+":"+pStr[2]+"\n");

					((CSmsApp*)AfxGetApp())->m_Log.LogMessage("发送"+pStr[1]+":"+pStr[2]);
					delete []pStr;
				}		
			}
			else
			{
				AfxMessageBox("请使用http协议");
				((CSmsApp*)AfxGetApp())->m_Log.LogMessage("输入的协议不正确");
			}
			//KillTimer(1);

			// Send the message.
			//SendTheMessage(strSmsc,strNumber,strContent);

			//AfxMessageBox("调用了定时函数");
		}
		break;
	default:
		break;
    }

	CDialog::OnTimer(nIDEvent);
}


CString* CDialog_Main::SplitString(CString str, char split, int& iSubStrs)
{
    int iPos = 0; //分割符位置
    int iNums = 0; //分割符的总数
    CString strTemp = str;
    CString strRight;
    //先计算子字符串的数量
    while (iPos != -1)
    {
        iPos = strTemp.Find(split);
        if (iPos == -1)
        {
            break;
        }
        strRight = strTemp.Mid(iPos + 1, str.GetLength());
        strTemp = strRight;
        iNums++;
    }
    if (iNums == 0) //没有找到分割符
    {
        //子字符串数就是字符串本身
        iSubStrs = 1; 
        return NULL;
    }
    //子字符串数组
    iSubStrs = iNums + 1; //子串的数量 = 分割符数量 + 1
    CString* pStrSplit;
    pStrSplit = new CString[iSubStrs];
    strTemp = str;
    CString strLeft;
    for (int i = 0; i < iNums; i++)
    {
        iPos = strTemp.Find(split);
        //左子串
        strLeft = strTemp.Left(iPos);
        //右子串
        strRight = strTemp.Mid(iPos + 1, strTemp.GetLength());
        strTemp = strRight;
        pStrSplit[i] = strLeft;
    }
    pStrSplit[iNums] = strTemp;
    return pStrSplit;
}


void CDialog_Main::OnKillfocusPeriodSend() 
{
	// TODO: Add your control notification handler code here

	CString	strPeriod;
	CTime tmTime = CTime::GetCurrentTime ();
	m_Period_Send.GetWindowText(strPeriod);
	
	if (strPeriod == "" || atoi(strPeriod) <= 0 )
	{
		m_Period_Send.SetWindowText("1");
		m_Status_Information.SetSel(-1, -1);
		m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"周期设置错误，请正确设置为大于0的整数\n");
		((CSmsApp*)AfxGetApp())->m_Log.LogMessage("周期设置错误，请正确设置为大于0的整数");
	}
	else
	{
		m_Status_Information.SetSel(-1, -1);
		m_Status_Information.ReplaceSel(tmTime.Format ("%m/%d/%y %H:%M:%S")+"周期设置为"+strPeriod+"\n");
		((CSmsApp*)AfxGetApp())->m_Log.LogMessage("周期设置为"+strPeriod);
	}
}

BOOL CDialog_Main::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE)  return TRUE;
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) 
	{

		switch (m_Status_Enter)
		{
			// set the period.
		case 0x01:
				//CDialog_Main::OnKillfocusPeriodSend();
				::SetFocus(NULL);
				m_Status_Enter = 0x00;
			break;
		case 0x02:
			break;
		default:
			{

			}
		}

		return TRUE;
	}
	else 
    return CDialog::PreTranslateMessage(pMsg);
}

void CDialog_Main::OnSetfocusPeriodSend() 
{
	// TODO: Add your control notification handler code here
	m_Status_Enter = 0x01;
}
