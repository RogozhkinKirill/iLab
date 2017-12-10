#ifndef _ERRORS_H_
#define _ERRORS_H_

#define error(code , name) name = code,

enum ERRORS
{
	error(0 , _OK_)
	_NULL_POINTER_ = -1,
	_STACK_OVERFLOW_ = 1,
	_YES_ = 1,
	_NO_ = 2,
};

typedef enum ERRORS ERRORS;


#endif // _ERRORS_H_
