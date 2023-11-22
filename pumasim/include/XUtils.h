#include "XPrintf.h"

#ifdef _DEBUG
#undef NDEBUG
#include <cassert>
#define SAIAssert(fCondition) assert(fCondition)
#define SAIAssertSz(fCondition, sz) assert(fCondition)
#else
#include <string>
#include <sstream>
#define SAIAssert(fCondition) if(!(fCondition)){std::stringstream message_ss; message_ss << std::string("ERROR in the condition ") << std::string(#fCondition) << " in file " << __FILE__ << ", line " << __LINE__ <<std::endl;fprintf(stdout,"%s\n",message_ss.str().c_str());fprintf(stderr,"%s\n",message_ss.str().c_str()); throw message_ss.str();}
#define SAIAssertSz(fCondition, sz) if(!(fCondition)){std::stringstream message_ss; message_ss << std::string("ERROR in the condition ") << std::string(#fCondition) << " in file " << __FILE__ << ", line " << __LINE__ <<std::endl;fprintf(stdout,"%s\n",message_ss.str().c_str());fprintf(stderr,"%s\n",message_ss.str().c_str()); throw message_ss.str();}
#endif
