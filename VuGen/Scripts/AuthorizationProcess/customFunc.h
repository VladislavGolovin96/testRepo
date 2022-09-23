//Функция для сохранения ответа

void saveResponse(){
	
	web_reg_save_param_ex(
		"ParamName=success",
		"LB=HTTP/1.1 ",
		"RB= OK",
		"NotFound=warning",
		SEARCH_FILTERS,
		"Scope=Headers",
		LAST);	
	
	return;
}

//Функция для сопоставления сохраненного параметра с ожидаемым результатом

void checkResponse(char* expectedStatement){
	
	if(strcmp(lr_eval_string("{success}"), "200") == 0) {
		lr_output_message("Статус ответа успешный");
	}else{
		lr_error_message("Получена ошибка от сервера ");
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE, LR_FAIL);
	}
	
	return;
	
}