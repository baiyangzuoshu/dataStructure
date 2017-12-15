# SingleLinkList
## 初识assert
1. `#define assert(expression) (void)(`     
            `(!!(expression)) ||  `                                                            
            `(_wassert(_CRT_WIDE(#expression), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)), 0)` 
        `)`  
2.由1我们不难知道它是一个宏定义。当assert传入一个0时，将会触发终止程序。  
3.当我们向上看到的时候，会看到#ifdef NDEBUG #define assert(expression) ((void)0),也就是说当我们正式发布软件的时候是不会触发终止程序的。  
## head、current的意义
1.head是链表的头结点，指向第一个节点  
2.current一开始指向的是head，current->next指向下一个节点。  
3.当我进行删除操作的时候，需要用last_缓存下上一个节点，这样last_->next=current_->next。  
4.head是一个对象实例，非指针。为什么怎么做呢？如果是指针的话，head->next操作，就需要为head分配内存了，所以才是对象实例，而非指针。  
## 小结
>>链表的巧妙之处在于，数据和节点首地址是重合的，数据包含着节点，且节点一定是在数据的顶部。
