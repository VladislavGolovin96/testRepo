/*  Скрипт "Процесс регистрации на сайте Web Tours" 
	Author: Golovin V.Sh
	16/09/2022 UPD:19.09.2022*/
Action()
{
	lr_start_transaction("Транзакция 1: Прогрузка главной страницы");
	saveResponse();
	
	web_custom_request("Web Tours",
	    "URL={http}{host}{port}/webtours/index.htm",
		"Method=GET",
		"Resource=0",
		"RecContentType=text/html",
		"Snapshot=t1.inf",
		LAST);
	
	checkResponse("Main");
	
	
	
	web_custom_request("header.html",
	"URL={http}{host}{port}/webtours/header.html",
	"Method=GET",
	"Resource=0",
	"RecContentType=text/html",
	"Snapshot=t2.inf",
	LAST);
	
	
	
	web_custom_request("welcome.pl",
	"URL={http}{host}{port}/cgi-bin/welcome.pl?signOff=true",
	"Method=GET",
	"Resource=0",
	"RecContentType=text/html",
	"Snapshot=t3.inf",
	LAST);
	
	web_custom_request("hp_logo.png",
	"URL={http}{host}{port}/webtours/images/hp_logo.png",
	"Method=GET",
	"Resource=0",
	"RecContentType=image/png",
	"Snapshot=t4.inf",
	LAST);
	
	web_custom_request("webtours.png",
	"URL={http}{host}{port}/webtours/images/webtours.png",
	"Method=GET",
	"Resource=0",
	"RecContentType=image/png",
	"Snapshot=t5.inf",
	LAST);
	
	web_custom_request("nav.pl",
	"URL={http}{host}{port}/cgi-bin/nav.pl?in=home",
	"Method=GET",
	"Resource=0",
	"RecContentType=text/html",
	"Snapshot=t6.inf",
	LAST);
	
	web_custom_request("home.html",
	"URL={http}{host}{port}/WebTours/home.html",
	"Method=GET",
	"Resource=0",
	"RecContentType=text/html",
	"Snapshot=t7.inf",
	LAST);
	
	web_custom_request("mer_login.gif",
	"URL={http}{host}{port}/WebTours/images/mer_login.gif",
	"Method=GET",
	"Resource=0",
	"RecContentType=image/gif",
	"Snapshot=t8.inf",
	LAST);
	
	lr_end_transaction("Транзакция 1: Прогрузка главной страницы", LR_AUTO);
	
	//Переход на страницу заполнения формы регистрации
	
	lr_start_transaction("Транзакция 2: Прогрузка формы регистрации");
	
	saveResponse();
	
	web_custom_request("Registration form",
	"URL={http}{host}{port}/cgi-bin/login.pl?username=&password=&getInfo=true",
	"Method=GET",
	"Resource=0",
	"RecContentType=text/html",
	"Snapshot=t9.inf",
	LAST);
	
	checkResponse("RegForm");
	
	web_custom_request("button_next.gif",
	"URL={http}{host}{port}/WebTours/images/button_next.gif",
	"Method=GET",
	"Resource=0",
	"RecContentType=image/gif",
	"Snapshot=t10.inf",
	LAST);
	
	lr_end_transaction("Транзакция 2: Прогрузка формы регистрации", LR_AUTO);
	
	lr_start_transaction("Транзакция 3: Отправка заполненных данных на бэк");
	
	saveResponse();
	web_custom_request("Отправка данных",
	"URL={http}{host}{port}/cgi-bin/login.pl",
	"Method=POST",
	"Resource=0",
	"RecContentType=application/x-www-form-urlencoded",
	"Body=username={logins}&password={passwords}&passwordConfirm={passwordsConf}&firstName={firstName}&lastName={lastName}&address1={address}&address2={adress2}&register.x=47&register.y=11",
	"Snapshot=t11.inf",
	LAST);
	checkResponse("sendingData");
	
	web_custom_request("button_next.gif",
	"URL={http}{host}{port}/WebTours/images/button_next.gif",
	"Method=GET",
	"Resource=0",
	"RecContentType=image/gif",
	"Snapshot=t12.inf",
	LAST);
	
	lr_end_transaction("Транзакция 3: Отправка заполненных данных на бэк",LR_AUTO);
	
	//Жмем Continue и переходим на домашнюю страницу
	
	lr_start_transaction("Транзакция 4: Редирект на главную страницу");
	saveResponse();
	
	web_custom_request("welcome.pl",
	"URL={http}{host}{port}/cgi-bin/welcome.pl?page=menus",
	"Method=GET",
	"Resource=0",
	"RecContentType=text/html",
	"Snapshot=t13.inf",
	LAST);
	
	checkResponse("RedirectToTheMain");
	
	web_custom_request("signoff.gif",
	"URL={http}{host}{port}/WebTours/images/signoff.gif",
	"Method=GET",
	"Resource=0",
	"RecContentType=image/gif",
	"Snapshot=t14.inf",
	LAST);
	
	saveResponse();
	
	web_custom_request("nav_1.pl",
	"URL={http}{host}{port}/cgi-bin/nav.pl?page=menu&in=home",
	"Method=GET",
	"Resource=0",
	"RecContentType=text/html",
	"Snapshot=t15.inf",
	LAST);
	
	checkResponse("nav_pl");
	
	saveResponse();
	
	web_custom_request("login_1.pl",
	"URL={http}{host}{port}/cgi-bin/login.pl?intro=true",
	"Method=GET",
	"Resource=0",
	"RecContentType=text/html",
	"Snapshot=t16.inf",
	LAST);
	
	checkResponse("loginp");
	
	web_custom_request("itinerary.gif",
	"URL={http}{host}{port}/WebTours/images/itinerary.gif",
	"Method=GET",
	"Resource=0",
	"RecContentType=image/gif",
	"Snapshot=t17.inf",
	LAST);
	
	web_custom_request("in_home.gif",
	"URL={http}{host}{port}/WebTours/images/in_home.gif",
	"Method=GET",
	"Resource=0",
	"RecContentType=image/gif",
	"Snapshot=t18.inf",
	LAST);
	
	web_custom_request("flights.gif",
	"URL={http}{host}{port}/WebTours/images/flights.gif",
	"Method=GET",
	"Resource=0",
	"RecContentType=image/gif",
	"Snapshot=t19.inf",
	LAST);
	
	lr_end_transaction("Транзакция 4: Редирект на главную страницу",LR_AUTO);
	
		return 0;
}
