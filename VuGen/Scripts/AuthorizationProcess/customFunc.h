//������� ��� ���������� ������

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

//������� ��� ������������� ������������ ��������� � ��������� �����������

void checkResponse(char* expectedStatement){
	
	if(strcmp(lr_eval_string("{success}"), "200") == 0) {
		lr_output_message("������ ������ ��������");
	}else{
		lr_error_message("�������� ������ �� ������� ");
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE, LR_FAIL);
	}
	
	return;
	
}