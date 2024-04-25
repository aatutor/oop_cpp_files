#include <iostream>
using namespace std;

#define PROTECTED 1

#if PUBLIC
	class Parent {
		private: 	int priv_;
		protected:int prot_;
		public: 	int pub_;
	};
	class Child : public Parent {
	public:
		void Foo() {
			// priv_ = 0; // fail
			prot_ = 1;		// ok
			pub_ = 2;			// ok
		}
	};

void TestPub() 
{
	Parent par;
	// par.priv_ = 0; // is private
	// par.prot_ = 0; // is protected
	par.pub_ = 1; 	// ok - public 

	Child ch;
	// ch.priv_ = 0;	// is private
	// ch.prot_ = 0;	// is protected
	ch.pub_ = 10; 	// ok - public
}
#endif

#if PRIVATE
	class Parent {
		private: 	int priv_;
		protected:int prot_;
		public: 	int pub_;
	};
	class Child : private Parent {
	public:
		void Foo() {
			// priv_ = 0; // fail
			prot_ = 1;		// ok
			pub_ = 2;			// ok
		}
	};
	class Baby : public Child {
	public:
		void Foo() {
			// priv_ = 0; // fail
			// prot_ = 1;	// fail
			// pub_ = 2;	// fail
		}
	};

void TestPriv() 
{
	Parent par;
	// par.priv_ = 0; // is private
	// par.prot_ = 0; // is protected
	par.pub_ = 1; 	// ok - public 

	Child ch;
	// ch.priv_ = 0; // is private
	// ch.prot_ = 0; // is private
	// ch.pub_ = 11; // is private

	Baby bb;
	// bb.priv_ = 0; // is private
	// bb.prot_ = 0; // is private
	// bb.pub_ = 22; // is private
}
#endif

#if PROTECTED
	class Parent {
		private: 	int priv_;
		protected:int prot_;
		public: 	int pub_;
	};
	class Child : protected Parent {
	public:
		void Foo() {
			// priv_ = 0; // fail
			prot_ = 1;		// ok
			pub_ = 2;			// ok
		}
	};
	class Baby : public Child {
	public:
		void Foo() {
			// priv_ = 0; // fail
			prot_ = 1;		// ok
			pub_ = 2;			// ok
		}
	};

void TestProt() 
{
	Parent par;
	// par.priv_ = 0; // is private
	// par.prot_ = 0; // is protected
	par.pub_ = 1; 	// ok - public 

	Child ch;
	// ch.priv_ = 0; // is private
	// ch.prot_ = 0; // is protected
	// ch.pub_ = 12; // is protected

	Baby bb;
	// bb.priv_ = 0; // is private
	// bb.prot_ = 0; // is protected
	// bb.pub_ = 22; // is protected
}
#endif

int main ()
{
#if PUBLIC
	TestPub();
#endif
#if PRIVATE
	TestPriv();
#endif
#if PROTECTED
	TestProt();
#endif

	return 0;
}
