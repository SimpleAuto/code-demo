/*
 *************************************************************************
 *    File Name:  soure_code.c
 *       Author: Thomas Beijing,Inc.
 *         Mail: 982737593@qq.com
 * Created Time: 2018年04月05日 星期四 15时12分56秒
 * 
 *  Description: ...
 * 
 *************************************************************************
*/
#include<stdio.h>

// _beginthreadex 在堆区创建了一块数据区域，把线程函数和参数放入了这块区域，
// 然后调用了CreateThread函数时，传入的并不是我们指定的线程函数，而是另一个函数 _threadstartex,而且参数是分配的data block
uintptr_r __cdecl _beginthreadex
(
void *psa,
unsigned cbStackSize;
unsigned (__stdcall * pfnStartAddr)(void*),
void *pvParam,
unsigned dwCreateFlags,
unsigned *pwdThreadID
)
{
    _ptiddata ptd;  // pointer to thread's data block
    uintptr_r thdl; //Thread's HANDLE

    //Allocate data block for new thread
    //为新线程分配数据区域
    if((ptd=(_ptiddata)_calloc_crt(1,sizeof(struct _tiddata))) == NULL) goto error_return;

    // Initilize the data block
    initptd(ptd);

    //Save the desired thread function and the parameter we want to get in the data block
    //将线程的函数和参数放入这块数据区域
    ptd->_initaddr = (void *)pfnStartAddr;
    ptd->_initarg = pvParam;
    ptd->_thandle = (uintptr_t)(-1);

    //Create the thread
    thdl = (uintptr_t)CreateThread((LPSECURITY_ATTRIBUTES)pas,cbStackSize,
            _threadstartex,(PVOID)ptd,dwCreateFlags,pwdThreadID);
    if(thdl == 0){
        // thread can not be created 
        goto error_return;
    }else{
        //返回线程句柄
        return (thdl); 
    }

error_return:
    // Error: data block or thread can not be created 

    _free_crt(ptd);
    return ((uintptr_t)L);
}

// mtdll.h
struct _tiddata {
    unsigned long   _tid;       /* thread ID */


    uintptr_t _thandle;         /* thread handle */

    int     _terrno;            /* errno value */
    unsigned long   _tdoserrno; /* _doserrno value */
    unsigned int    _fpds;      /* Floating Point data segment */
    unsigned long   _holdrand;  /* rand() seed value */
    char *      _token;         /* ptr to strtok() token */
    wchar_t *   _wtoken;        /* ptr to wcstok() token */
    unsigned char * _mtoken;    /* ptr to _mbstok() token */

    /* following pointers get malloc'd at runtime */
    char *      _errmsg;        /* ptr to strerror()/_strerror() buff */
    wchar_t *   _werrmsg;       /* ptr to _wcserror()/__wcserror() buff */
    char *      _namebuf0;      /* ptr to tmpnam() buffer */
    wchar_t *   _wnamebuf0;     /* ptr to _wtmpnam() buffer */
    char *      _namebuf1;      /* ptr to tmpfile() buffer */
    wchar_t *   _wnamebuf1;     /* ptr to _wtmpfile() buffer */
    char *      _asctimebuf;    /* ptr to asctime() buffer */
    wchar_t *   _wasctimebuf;   /* ptr to _wasctime() buffer */
    void *      _gmtimebuf;     /* ptr to gmtime() structure */
    char *      _cvtbuf;        /* ptr to ecvt()/fcvt buffer */
    unsigned char _con_ch_buf[MB_LEN_MAX];
                                /* ptr to putch() buffer */
    unsigned short _ch_buf_used;   /* if the _con_ch_buf is used */

    /* following fields are needed by _beginthread code */
    void *      _initaddr;      /* initial user thread address */
    void *      _initarg;       /* initial user thread argument */

    /* following three fields are needed to support signal handling and
     * runtime errors */
    void *      _pxcptacttab;   /* ptr to exception-action table */
    void *      _tpxcptinfoptrs; /* ptr to exception info pointers */
    int         _tfpecode;      /* float point exception code */

    /* pointer to the copy of the multibyte character information used by
     * the thread */
    pthreadmbcinfo  ptmbcinfo;

    /* pointer to the copy of the locale informaton used by the thead */
    pthreadlocinfo  ptlocinfo;
    int         _ownlocale;     /* if 1, this thread owns its own locale */

    /* following field is needed by NLG routines */
    unsigned long   _NLG_dwCode;

    /*
     * Per-Thread data needed by C++ Exception Handling
     */
    void *      _terminate;     /* terminate() routine */
    void *      _unexpected;    /* unexpected() routine */
    void *      _translator;    /* S.E. translator */
    void *      _purecall;      /* called when pure virtual happens */
    void *      _curexception;  /* current exception */
    void *      _curcontext;    /* current exception context */
    int         _ProcessingThrow; /* for uncaught_exception */
    void *      _curexcspec;    /* for handling exceptions thrown from std::unexpected */
#if defined (_M_X64) || defined (_M_ARM)
    void *      _pExitContext;
    void *      _pUnwindContext;
    void *      _pFrameInfoChain;
#if defined (_WIN64)
    unsigned __int64    _ImageBase;
    unsigned __int64    _ThrowImageBase;
#else  /* defined (_WIN64) */
    unsigned __int32    _ImageBase;
    unsigned __int32    _ThrowImageBase;
#endif  /* defined (_WIN64) */
    void *      _pForeignException;
#elif defined (_M_IX86)
    void *      _pFrameInfoChain;
#endif  /* defined (_M_IX86) */
    _setloc_struct _setloc_data;

    void *      _reserved1;     /* nothing */
    void *      _reserved2;     /* nothing */
    void *      _reserved3;     /* nothing */
#ifdef _M_IX86
    void *      _reserved4;     /* nothing */
    void *      _reserved5;     /* nothing */
#endif  /* _M_IX86 */

    int _cxxReThrow;        /* Set to True if it's a rethrown C++ Exception */

    unsigned long __initDomain;     /* initial domain used by _beginthread[ex] for managed function */
#if defined(_CRT_APP) && !defined(_KERNELX)
    HANDLE _winRTThreadHandle;     /* App CRT WinRT thread handle */
#else  /* _CRT_APP */
    int           _initapartment;   /* if 1, this thread has initialized apartment */
#endif  /* _CRT_APP */
    _psetloc_downlevel_struct _setloc_downlevel_data;
};

// 43R,44R 调用CreateThread时的传入的函数 _threadstartex调用点
static unsigned long WINAPI _threadstartex(void *ptd) 
{ 
// Note:ptd is the address of this thread’s tiddata block. 
//Associate the tiddata block with this thread so _getptd() will be able to find it in _callthreadstartex. 
	TlsSetValue(__tlsindex,ptd);

	// Save this thread ID in the _tiddata block.
	((_ptiddata)ptd)->_tid = GetCurrentThreadId();

	_callthreadstartex();

	// We never get here ;  the thread dies in _callthreadstartex.
	return (0L);
}

static void _callthreadstartex(void){ 
	_ptiddata ptd; 
	//获取data block ，（用TlsSetValue设置的） 
	ptd = _getptd();

	//Wrap desired thread function in SEH frame to handle run-time errors and signal support.

	__try{
		//调用线程函数
		_endthreadex(ptd._initaddr( ptd._initarg ));
	}
	__except(_XcpFilter(GetExceptionCode(),GetExceptionInformation())){
		_exit(GetExceptionCode());
	}
}

// _endthreadex的伪代码
void __cdecl _endthreadex (unsigned retcode) 
{ 
	_ptiddata ptd;// pointer to datablock 
	//Clean up floating-point support

	// Get the address of this thread's tiddata block.
	ptd = _getptd_noexti();

	//Free the data block
	if(ptd != NULL) _freeptd(ptd);

	// Terminate thread 
	ExitThread(retcode);
}

/*
 * 经过上面的的分析我们在创建线程和结束线程时应该用 _beginthreadstartex和 _endthreadex,
 * 因为他会帮我们维护thread local的数据结构，
 * 假如有人就直接用CreateThread会怎么样呢？
 * 如果线程要用到threadlocal的数据结构，但是由于是使用CreateThread创建的线程，
 * 还没有那个data block ，这里C/C++运行库会帮我们创建一个_tiddata的数据结构，
 * 这样基本上是可以正常使用的，但是由于没有初始化SEH（异常处理）帧，
 * 当我们使用signal函数是，程序会退出整个进程，
 * 如果退出的时候没有用_endthreadex的话，由于没有释放_tiddata 数据结构，会导致内存泄露。
 */



