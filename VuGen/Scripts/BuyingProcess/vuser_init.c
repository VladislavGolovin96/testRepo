vuser_init()
{
	lr_save_int(200, "success");
	if(atoi(lr_eval_string("{success}"))== 0){
		lr_output_message("hello + %d",lr_eval_string("{success}"));
	}
	return 0;
}
