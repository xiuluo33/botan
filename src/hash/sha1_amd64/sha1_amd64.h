/*************************************************
* SHA-160 (x86-64) Header File                   *
* (C) 1999-2007 Jack Lloyd                       *
*************************************************/

#ifndef BOTAN_SHA_160_AMD64_H__
#define BOTAN_SHA_160_AMD64_H__

#include <botan/mdx_hash.h>

namespace Botan {

/*************************************************
* SHA-160                                        *
*************************************************/
class BOTAN_DLL SHA_160_AMD64 : public MDx_HashFunction
   {
   public:
      void clear() throw();
      std::string name() const { return "SHA-160"; }
      HashFunction* clone() const { return new SHA_160_AMD64; }

      SHA_160_AMD64() : MDx_HashFunction(20, 64, true, true) { clear(); }
   private:
      void hash(const byte[]);
      void copy_out(byte[]);

      SecureBuffer<u32bit, 5> digest;
      SecureBuffer<u32bit, 80> W;
   };

}

#endif
