/*  Скрипт "Процесс прогрузки домашней страницы" 
	Author: Golovin V.Sh
	16/09/2022 UPD:19.09.2022*/
Action()

{
	//Начало транзакции 

	lr_start_transaction("Транзакция 2: Загрузка домашней страницы");
	
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
	
	lr_think_time (10);
	
	web_custom_request("nav_1.pl",
	    "URL={http}{host}{port}/cgi-bin/nav.pl?in=home",
		"Method=GET",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={http}{host}{port}/cgi-bin/welcome.pl?signOff=true",
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
	
		
	lr_think_time (10);
	
	web_custom_request("mer_login.gif",
		"URL={http}{host}{port}/WebTours/images/mer_login.gif",
		"Method=GET",
		"Resource=0",
		"RecContentType=image/gif",
		"Snapshot=t8.inf",
		LAST);

	lr_end_transaction("Транзакция 2: Загрузка домашней страницы", LR_AUTO);
	
	return 0;
}
