/*  Скрипт "Процесс покупки билета и возврата на домашнюю страницу" 
	Author: Golovin V.Sh
	16/09/2022 UPD:19.09.2022*/

Action()

	

{
	//Начало транзакции 

	lr_start_transaction("Транзакция 1: Время авторизации");

	lr_start_transaction("Транзакция 3: Процесс покупки билета с возвращением на домашнюю страницу");
	
	//Прогрузка домашней страницы
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
	
	lr_think_time (10);
	
	web_custom_request("signoff.gif",
		"URL={http}{host}{port}/WebTours/images/signOff.gif",
		"Method=GET",
		"Resource=0",
		"RecContentType=text/html",
		"Snapshot=t15.inf",
		LAST);
	
	lr_think_time (10);	  

	lr_end_transaction("Транзакция 1: Время авторизации", LR_AUTO);
		
		
	//Осуществление перехода на экран выбора авирейсов
	
	saveResponse();
	
	web_custom_request("nav_3.pl",
	    "URL={http}{host}{port}/cgi-bin/nav.pl?page=menu&in=flights",
	    "Method=GET",
	    "Resource=0",
	   	"RecContentType=text/html",
	    "Snapshot=t17.inf",
	    LAST);
	
	checkResponse("FlightListScreen");
	
	web_custom_request("reservations.pl",
	    "URL={http}{host}{port}/cgi-bin/reservations.pl?page=welcome",
	    "Method=GET",
	    "Resource=0",
	    "RecContentType=text/html",
	    "Snapshot=t18.inf",
	    LAST);
	
	web_custom_request("inflights.gif",
	    "URL={http}{host}{port}/WebTours/images/in_flights.gif",
	    "Method=GET",
	    "Resource=0",
	    "RecContentType=image/gif",
	    "Snapshot=t19.inf",
	    LAST);
	
	web_custom_request("itinerary.gif",
	    "URL={http}{host}{port}/WebTours/images/itinerary.gif",
	    "Method=GET",
	    "Resource=0",
	    "RecContentType=image/gif",
	    "Snapshot=t20.inf",
	    LAST);
	
	web_custom_request("home.gif",
	    "URL={http}{host}{port}/WebTours/images/home.gif",
	    "Method=GET",
	    "Resource=0",
	    "RecContentType=image/gif",
	    "Snapshot=t21.inf",
	    LAST);
	
	web_custom_request("signoff.gif",
	    "URL={http}{host}{port}/WebTours/images/signOff.gif",
	    "Method=GET",
	    "Resource=0",
	    "RecContentType=image/gif",
	    "Snapshot=t22.inf",
	    LAST);
	
	web_custom_request("button_next.gif",
	    "URL={http}{host}{port}/WebTours/images/button_next.gif",
	    "Method=GET",
	    "Resource=0",
	    "RecContentType=image/gif",
	    "Snapshot=t23.inf",
	    LAST);
	
	//Осуществление перехода на экран поиска билетов с выбранными параметрами
	
	web_reg_save_param_ex(
		"ParamName=outBound",
		"LB=\"outboundFlight\" value=\"",
		"RB=\"",
		"NotFound=Error",
		SEARCH_FILTERS,
    	"Scope=Body",
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=returnFlight",
		"LB=\"returnFlight\" value=\"",
		"RB=\"",
		"NotFound=Error",
		SEARCH_FILTERS,
    	"Scope=Body",
		LAST);
	
	saveResponse();
	
	web_custom_request("reservation_2.pl",
	    "URL={http}{host}{port}/cgi-bin/reservations.pl",
	    "Method=POST",
	    "Resource=0",
	    "RecContentType=application/x-www-form-urlencoded",
	    "Snapshot=t24.inf",
	    "Body=advanceDiscount=0&depart={DepartCity}&departDate={departDate}&arrive={ArrivalCity}&returnDate=09%2F25%2F2022&numPassengers=1&roundtrip={roundTrip}&seatPref={seatPref}&seatType={seatType}&findFlights.x=43&findFlights.y=8&.cgifields=roundtrip&.cgifields=seatType&.cgifields=seatPref",
	    LAST);
	
	checkResponse("FindFlightsScreen");
	
	lr_output_message(lr_eval_string("Информация по рейсу отправления={outBound}"));
	
	
	lr_output_message(lr_eval_string("Информация по рейсу прибывания={returnFlight}"));
	
	//Осуществление перехода на экран ввода деталей платежа с выбранными рейсами
	
	saveResponse();
	
	web_custom_request("reservation_3.pl",
	    "URL={http}{host}{port}/cgi-bin/reservations.pl",
	    "Method=POST",
	    "Resource=0",
	    "RecContentType=application/x-www-form-urlencoded",
	    "Snapshot=t25.inf",
	    "Body=outboundFlight={outBound}&returnFlight={returnFlight}&numPassengers=1&advanceDiscount=0&seatType={seatType}&seatPref={seatPref}&reserveFlights.x=53&reserveFlights.y=11",
	    LAST);
	
	checkResponse("screenDetail");
	
	web_custom_request("button_next.gif",
	  	"URL={http}{host}{port}/WebTours/images/button_next.gif",
	  	"Method=GET",
	  	"Resource=0",
	  	"RecContentType=image/gif",
	  	"Snapshot=t26.inf",
	  	LAST);
	
	//Осуществление перехода на финальный экран с указанными деталями по платежу
	
	saveResponse();
	
	web_custom_request("reservation_4.pl",
	  	"URL={http}{host}{port}/cgi-bin/reservations.pl",
	  	"Method=POST",
	  	"Resource=0",
	  	"RecContentType=application/x-www-form-urlencoded",
	  	"Snapshot=t27.inf",
	  	LAST);
	
	checkResponse("finalScreen");
	
	web_custom_request("bookanother.gif",
	  	"URL={http}{host}{port}/WebTours/images/bookanother.gif",
	  	"Method=GET",
	  	"Resource=0",
	  	"RecContentType=image/gif",
	  	"Snapshot=t28.inf",
	  	LAST);
	
	//Возвращаемся на главную страницу
	
	saveResponse();
	web_custom_request("goingToTheHomePage",
	  	"URL={http}{host}{port}/cgi-bin/welcome.pl?page=menus",
	  	"Method=GET",
	  	"Resource=0",
	  	"RecContentType=text/html",
	  	"Snapshot=t29.inf",
	  	LAST);
	
	checkResponse("goToTheHomePage");
	
	web_custom_request("nav_5.pl",
	  	"URL={http}{host}{port}/cgi-bin/nav.pl?page=menu&in=home",
	  	"Method=GET",
	  	"Resource=0",
	  	"RecContentType=text/html",
	  	"Snapshot=t30.inf",
	  	LAST);
	
	web_custom_request("login.pl",
	  	"URL={http}{host}{port}/cgi-bin/login.pl?intro=true",
	  	"Method=GET",
	  	"Resource=0",
	  	"RecContentType=text/html",
	  	"Snapshot=t31.inf",
	  	LAST);
	
	web_custom_request("itinerarry.gif",
		"URL={http}{host}{port}/WebTours/images/itinerary.gif",
		"Method=GET",
		"Resource=0",
		"RecContentType=image/gif",
		"Snapshot=t32.inf",
		LAST);
	
	web_custom_request("signoff.gif",
	    "URL={http}{host}{port}/WebTours/images/signOff.gif",
	    "Method=GET",
	    "Resource=0",
	    "RecContentType=image/gif",
	    "Snapshot=t33.inf",
	    LAST);
	
	web_custom_request("flights.gif",
		"URL={http}{host}{port}/WebTours/images/flights.gif",
		"Method=GET",
		"Resource=0",
		"RecContentType=image/gif",
		"Snapshot=t34.inf",
		LAST);
		
	web_custom_request("inhome.gif",
	  	"URL={http}{host}{port}/WebTours/images/in_home.gif",
	  	"Method=GET",
	  	"Resource=0",
	  	"RecContentType=image/gif",
	  	"Snapshot=t35.inf",
	  	LAST);
	
	lr_end_transaction("Транзакция 3: Процесс покупки билета с возвращением на домашнюю страницу", LR_AUTO);
	
		return 0;
}