#pragma once

#include<memory>


namespace experimental {

	template<typename T>
	class function;

	template<typename RetType, typename ...Args>
	class function<RetType(Args...)> {

	private:

		class WrapperBase {
		public:
			virtual ~WrapperBase() {};
			virtual RetType Invoke(Args... args) = 0;

		};


		template <typename T>
		class Wrapper : public WrapperBase {
		private:
			T t_;
		public:


			Wrapper(T t) {
				t_ = t;

			}

			RetType Invoke(Args... args) {

				return t_(args...);
			}

		};


		std::unique_ptr<WrapperBase> wbp;

	public:

		template <typename T>
		function& operator= (T t) {

			wbp = make_unique<Wrapper<T>>(t);

			return *this;

		}


		template <typename T>
		function(T t) {

			wbp = std::make_unique<Wrapper<T>>(t);


		}

		function() {}


		RetType operator() (Args... args) {

			return wbp->Invoke(args...);
		}


	};





















}
