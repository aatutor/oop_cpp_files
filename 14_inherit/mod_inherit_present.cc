
#if PUBLIC
	class Parent {
		private: 	int priv_;
		protected: 	int prot_;
		public: 	int pub_;
	};
	class Child : public Parent {
		unaccessable:int priv_;
		protected: 	int prot_;
		public: 	int pub_;
	};
#endif

#if PROTECTED
	class Parent {
		private: 	int priv_;
		protected:	int prot_;
		public: 	int pub_;
	};
	class Child : protected Parent {
		unaccessable: 	int priv_;
		protected: 	int prot_;
		protected: 	int pub_;
	};
	class Baby : public Child {
		unaccessable: 	int priv_;
		protected: 	int prot_;
		protected: 	int pub_;
	};
#endif

#if PRIVATE
	class Parent {
		private: 	int priv_;
		protected:	int prot_;
		public: 	int pub_;
	};
	class Child : private Parent {
		unaccessable: 	int priv_;
		private: 	int prot_;
		private: 	int pub_;
	};
	class Baby : public Child {
		unaccessable: 	int priv_;
		unaccessable: 	int prot_;
		unaccessable: 	int pub_;
	};
#endif