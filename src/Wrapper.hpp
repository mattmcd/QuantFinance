#ifndef WRAPPER_HPP
#define WRAPPER_HPP

#include <memory>

// Wrapper to manage rule of 3 for an underlying DataPtr by cloning the
// pointer on create or copy
template <class T> 
class Wrapper
{
  public:
    Wrapper( ) {
      // Default constructor is needed to allow use with containers
      // such as std::vector
      DataPtr = NULL;
    }

    Wrapper( T *dataPtr) {
      // Ctor from pointer to object.  Take ownership of the pointer
      // by wrapping in std::unique_ptr 
      DataPtr = std::unique_ptr<T>( dataPtr );
    } 

    Wrapper( const T &data ) {
      // Ctor from ref to object.  Have the object clone itself and
      // return a pointer to the object.  Store this as a uniqe_ptr.
      DataPtr = std::unique_ptr<T>( data.clone() );
    }

    Wrapper( const Wrapper<T> &wrappedPtr ) {
      // Ctor from wrapped ptr.
      if (wrappedPtr.DataPtr  != NULL )
        DataPtr = std::unique_ptr<T>( wrappedPtr.DataPtr->clone() );
      else
        DataPtr = NULL;
    }

    // Destructor handled by unique_ptr 
    // (TODO: test this)

    // Dereference pointer to get refernce to object
    T& operator*() const {
      return *DataPtr;
    }

    T& operator*() {
      return *DataPtr;
    }

    // Access method of object
    std::unique_ptr<T> operator->() {
      return DataPtr;
    }

    const std::unique_ptr<T> operator->() {
      return DataPtr;
    }

  private:
    std::unique_ptr<T> DataPtr;
};

#endif
