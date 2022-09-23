/*  Скрипт "Процесс авторизации" 
	Author: Golovin V.Sh
	16/09/2022 UPD:19.09.2022*/
Action()
{
	//Начало транзакции 

	lr_start_transaction("Транзакция 1: Время авторизации");

	saveResponse();
	
	web_custom_request("Web Tours",
	    "URL={http}{host}{port}/webtours/index.htm",
		"Method=GET",
		"Resource=0",
		"RecContentType=text/html",
		"Snapshot=t1.inf",
		LAST);

	checkResponse("LogInPage");
	
	lr_think_time (10);
	
	web_custom_request("header.html",
	    "URL={http}{host}{port}/webtours/header.html",
		"Method=GET",
		"Resource=0",
		"RecContentType=text/html",
		"Snapshot=t2.inf",
		LAST);
	
	lr_think_time (10);
	
	
	//Сетим куку SID
	web_reg_save_param_ex(
		"ParamName=SID",
		"LB=MSO\=",
		"RB=\;",
		"NotFound=ERROR",
		SEARCH_FILTERS,
		"Scope=Headers",
		LAST);
	
	saveResponse();
	
	web_custom_request("welcome.pl",
	    "URL={http}{host}{port}/cgi-bin/welcome.pl?signOff=true",
		"Method=GET",
		"Resource=0",
		"RecContentType=text/html",
		"Snapshot=t3.inf",
		LAST);
	
	checkResponse("MainPage");
	
	lr_output_message(lr_eval_string("Кука={SID}"));
	
	
	//web_add_cookie(lr_eval_string("MSO={SID}"));

	
	
	lr_think_time (110);
	
	web_custom_request("hp_logo.png",
	    "URL={http}{host}{port}/webtours/images/hp_logo.png",
		"Method=GET",
		"Resource=0",
		"RecContentType=image/png",
		"Snapshot=t4.inf",
		LAST);
	
	
	lr_think_time (110);
	
	web_custom_request("webtours.png",
	    "URL={http}{host}{port}/webtours/images/webtours.png",
		"Method=GET",
		"Resource=0",
		"RecContentType=image/png",
		"Snapshot=t5.inf",
		LAST);
	
	//Получаем сессию пользователя
	web_reg_save_param_ex(
    "ParamName=userSession", 
    "LB=\"userSession\" value=\"",
    "RB=\"",
    SEARCH_FILTERS,
    "Scope=body",
	LAST);
	
	lr_think_time (100);
	
	web_custom_request("nav_1.pl",
	    "URL={http}{host}{port}/cgi-bin/nav.pl?in=home",
		"Method=GET",
		"Resource=0",
		"RecContentType=text/html",
		"Snapshot=t6.inf",
		LAST);
	lr_output_message(lr_eval_string("userSession={userSession}"));
	
	lr_think_time (10);
	
	web_custom_request("home.html",
	    "URL={http}{host}{port}/WebTours/home.html",
		"Method=GET",
		"Resource=0",
		"RecContentType=text/html",
		"Snapshot=t7.inf",
		LAST);
	
		
	lr_think_time (100);
	
	web_custom_request("mer_login.gif",
		"URL={http}{host}{port}/WebTours/images/mer_login.gif",
		"Method=GET",
		"Resource=0",
		"RecContentType=image/gif",
		"Snapshot=t8.inf",
		LAST);

	lr_think_time (10);	
	
	//Сетим куку MTUserInfo
	web_reg_save_param_ex(
		"ParamName=MTUserInfo",
		"LB=MTUserInfo\=",
		"RB=\;",
		"NotFound=ERROR",
		SEARCH_FILTERS,
		"Scope=Headers",
		LAST);
			
	web_custom_request("login_44.pl",
		"URL={http}{host}{port}/cgi-bin/login.pl",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/x-www-form-urlencoded",
		"Snapshot=t9.inf",
		"Body=userSession={userSession}&username={login}&password={password}&login.x=81&login.y=6&JSFormSubmit=off",
		LAST);
		
	lr_output_message(lr_eval_string("Кука 2={MTUserInfo}"));
	
	lr_think_time (110);
	
	//web_add_cookie(lr_eval_string("MSO={SID}; MTUserInfo={MTUserInfo}")); ??
	
	saveResponse();
	
	web_custom_request("nav_2.pl",
		"URL={http}{host}{port}/cgi-bin/nav.pl?page=menu&in=home",
		"Method=GET",
		"Resource=0",
		"RecContentType=text/html",
		"Snapshot=t10.inf",
		LAST);
	
	checkResponse("HomePage");
	
	web_custom_request("login_1.pl",
		"URL={http}{host}{port}/cgi-bin/login.pl?intro=true",
		"Method=GET",
		"Resource=0",
		"RecContentType=text/html",
		"Snapshot=t11.inf",
		LAST);
	
	lr_think_time (10);
	
	web_custom_request("flights.gif",
		"URL={http}{host}{port}/WebTours/images/flights.gif",
		"Method=GET",
		"Resource=0",
		"RecContentType=image/gif",
		"Snapshot=t12.inf",
		LAST);
	
	lr_think_time (110);
	
	web_custom_request("itinerarry",
		"URL={http}{host}{port}/WebTours/images/itinerary.gif",
		"Method=GET",
		"Resource=0",
		"RecContentType=image/gif",
		"Snapshot=t13.inf",
		LAST);
	
	lr_think_time (110);
	
	web_custom_request("in_home.gif",
		"URL={http}{host}{port}/WebTours/images/in_home.gif",
		"Method=GET",
		"Resource=0",
		"RecContentType=text/html",
		"Snapshot=t14.inf",
		LAST);
	
	lr_think_time (100);
	
	web_custom_request("signoff.gif",
		"URL={http}{host}{port}/WebTours/images/signoff.gif",
		"Method=GET",
		"Resource=0",
		"RecContentType=text/html",
		"Snapshot=t15.inf",
		LAST);
	
	lr_think_time (100);	  

	lr_end_transaction("Транзакция 1: Время авторизации", LR_AUTO);
	
	return 0;
}
