/* This class contains the Hascell List. Many of it's functions have destructive
 * and non-destructive functions. As a convention, all destructive functions
 * (aside from the constructor and destructor) are suffixed with a 'D'. It's
 * public functions include:
 *
 *     ________________________________________________________________________
 *     | Function          | Description                                      |
 *     |-------------------|--------------------------------------------------|
 *     |List(A)            | Creates a new singleton list.                    |
 *     |-------------------|--------------------------------------------------|
 *     |List(A, List<A>)   | Creates a new list with the first value at the   |
 *     |                   | top and the other list as the rest.              |
 *     |-------------------|--------------------------------------------------|
 *     |first()            | Returns the first element in the list.           |
 *     |-------------------|--------------------------------------------------|
 *     |rest()             | Returns the list without the first element.      |
 *     |-------------------|--------------------------------------------------|
 *     |last()             | Returns the last value in the list.              |
 *     |-------------------|--------------------------------------------------|
 *     |append(List<A>)    | Returns the specified list appended to the       |
 *     |                   | the current list.                                |
 *     |-------------------|--------------------------------------------------|
 *     |clear()            | Deletes all of the values from the list.         |
 *     |-------------------|--------------------------------------------------|
 *     |reverse()          | Returns the list in reverse order.               |
 *     |-------------------|--------------------------------------------------|
 *     |length()           | Returns the length of the list.                  |
 *     |-------------------|--------------------------------------------------|
 *     |[int]              | Returns the value at the specified element in the|
 *     |                   | list.                                            |
 *     |-------------------|--------------------------------------------------|
 *     |butLast()          | Returns a list without the last element          |
 *     |-------------------|--------------------------------------------------|
 *     |isEmpty()          | Returns true if the list is empty.               |
 *     |-------------------|--------------------------------------------------|
 *     |map(Function)      | Apply a function to every value in the list.     |
 *     |-------------------|--------------------------------------------------|
 *     |filter(Function)   | Given a function, will filter all of the items   |
 *     |                   | in the list where it returns false.              |
 *     |-------------------|--------------------------------------------------|
 *     |foldl(Function, B) | Fold the list from the list using the specified  |
 *     |                   | function, using the initial value B. If the list |
 *     |                   | is of type A, the function should be of type     |
 *     |                   | (B -> A -> B). This function returns the last    |
 *     |                   | B value that the function returns, or the passed-|
 *     |                   | in B value if  the list is empty.                |
 *     |-------------------|--------------------------------------------------|
 *     |foldr(Function, B) | Similar to foldr, but from the right instead of  |
 *     |                   | the left.                                        |
 *     |___________________|__________________________________________________|
 * 
 * Author: Tom Hulihan
 * email: hulihan.tom159@gmail.com
 **/

#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>
#include <string>
#include <sstream>
#include "Exceptions.h"
#include "Monad.h"
#include "Showable.h"

template <typename A>
class List : public Showable
{
    public:
        List()
        {
            head = NULL;
        }
        List(A val)
        {
            head = new Node<A>(val);
        }
        List(A val, List<A> list)
        {
            head = new Node<A>(val);
            if(list.isEmpty())  {
                head->next = NULL;
                return;
            }
            head->next = new Node<A>;
            Node<A>* myIt = head->next;
            Node<A>* otherIt = list.head;
            while(otherIt)
            {
                myIt->value = otherIt->value;
                otherIt = otherIt->next;
                if(otherIt)
                {
                    myIt->next = new Node<A>;
                    myIt = myIt->next;
                }
            }
            
        }

        List(const List<A>& list)
        {
            if(list.isEmpty())  {
                head = NULL;
                return;
            }
            head = new Node<A>;
            Node<A>* myIt = head;
            Node<A>* otherIt = list.head;
            while(otherIt)
            {
                myIt->value = otherIt->value;
                otherIt = otherIt->next;
                if(otherIt)
                {
                    myIt->next = new Node<A>;
                    myIt = myIt->next;
                }
            }
        }
        
        ~List()
        {
            clear();
        }

        void cons(A val)
        {
            Node<A>* oldHead = head;
            head = new Node<A>(val);
            head->next = oldHead;
        }

        void clear()
        {
            Node<A>* temp;
            while(head)
            {
                temp = head;
                head = head->next;
                delete temp;
            }

        }

        inline bool isEmpty() const
        {
            return (head == NULL);
        }
        

        A first() const
        {
            if(isEmpty())
                throw EmptyListError();
            else
                return head->value;
        }

        List<A> rest() const
        {
            if(!head)
                throw EmptyListError();
            Node<A>* inIt = head->next;
            if(!inIt)
                return List<A>();
            Node<A>* newHead = new Node<A>;
            Node<A>* outIt = newHead;

            while(inIt)
            {
                outIt->value = inIt->value;
                inIt = inIt->next;
                if(inIt)
                {
                    outIt->next = new Node<A>;
                    outIt = outIt->next;
                }
            }
            return List<A>(newHead);
        }

        A restD()
        {
            if(isEmpty())
                throw EmptyListError();
            Node<A>* deleteIt = head;
            A val = head->value;
            head = head->next;
            delete deleteIt;
            return val;
        }

        A last() const
        {
            if(isEmpty())
                throw EmptyListError();

            Node<A>* it = head;
            while(it->next)
                it = it->next;
            return it->value;
        }

        List<A> butLast() const
        {
            if(isEmpty())
                throw EmptyListError();
            else if(rest().isEmpty())
                return List<A>();
            else
                return List<A>(first(), rest().butLast());
        }

        A butLastD()
        {
            if(isEmpty())
                throw EmptyListError();
            Node<A>* prev = NULL;
            Node<A>* it = head;
            A returnValue;
            while(it->next)
            {
                prev = it;
                it = it->next;
            }

            if(prev)
            {
                prev->next = NULL;
                returnValue = it->value;
                delete it;
                return returnValue;
            }
            else
            {
                returnValue = head->value;
                delete head;
                return returnValue;
            }
        }

        List<A> append(List<A> list) const
        {
            if(isEmpty())
                return list;
            else
                return List<A>(first(), rest().append(list));
        }

        void appendD(List<A>& list)
        {
            if(list.isEmpty())
                return;

            Node<A>* curr = head;
            Node<A>* prev = NULL;
            while(curr)
            {
                prev = curr;
                curr = curr->next;
            }
            if(prev)
                prev->next = list.head;
            else
                head = list.head;
            list.head = NULL;
        }

        template <typename B, typename Function>
        List<B> map(Function f) const
        {
            if(isEmpty())
                return List<B>();
            else
                return List<B>((*f)(first()), rest().map<B>(f));
        }

        template <typename Function>
        void mapD(Function f)
        {
            Node<A>* it = head;
            A tempVal;
            while(it)
            {
                tempVal = it->value;
                it->value = (*f)(tempVal);
                it = it->next;
            }
        }

        List<A> reverse() const
        {
            if(isEmpty())
                return List<A>();
            else
                return List<A>(last(), butLast().reverse());
        }

        void reverseD()
        {
            Node<A>* prev = NULL;
            Node<A>* curr = head;
            Node<A>* temp = NULL;
            while(curr)
            {
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            head = prev;
        }

        template <typename Function>
        List<A> filter(Function f) const
        {
            if(isEmpty())
                return List<A>();
            A tempVal = head->value;
            if((*f)(tempVal))
                return List<A>(first(), rest().filter(f));
            else
                return rest().filter(f);
        }

        template <typename Function>
        void filterD(Function f)
        {
            Node<A>* prev = NULL;
            Node<A>* it = head;
            Node<A>* deleteIt = NULL;
            A tmp;
            while(it)
            {
                tmp = it->value;
                if((*f)(tmp))
                    it = it->next;
                else
                {
                    deleteIt = it;
                    it = it->next;
                    if(prev)
                        prev->next = it;
                    delete deleteIt;
                }
                prev = it;
            }
        }

        template <typename B, typename Function>
        B foldl(Function f, B bVal) const
        {
            Node<A>* it = head;
            A tempAVal;
            B tempBVal;
            while(it)
            {
                tempAVal = it->value;
                tempBVal = bVal;
                bVal = (*f)(tempAVal, tempBVal);
                it = it->next;
            }
            return bVal;
        }

        template <typename B, typename Function>
        B foldr(Function f, B bVal) const
        {
            if(isEmpty())
                return bVal;
            else
                return (*f)(first(), rest().foldr(f, bVal));
        }

        
        int length() const
        {
            int size = 0;
            Node<A>* it = head;
            while(it)
            {
                it = it->next;
                size++;
            }
            return size;
        }

        A operator[] (int n)
        {
            Node<A>* thisIt = head;
            while((n--) && thisIt)
            {
                thisIt = thisIt->next;
            }
            if(n > 0)
                throw EmptyListError();
            else
                return thisIt->value;
        }
        
        std::string Show(void)
        {
            std::ostringstream os;
            Node<A>* thisIt = head;
            os << '[';
            while(thisIt)
            {
                os << thisIt->value;
                thisIt = thisIt->next;
                if(thisIt)
                    os << ',';
            }
            os << ']';
            return os.str();
        }

        /*
        static List<A> inject(A val)
        {
            return List<A>(val);
        }

        template <typename B>
        List<B> bind(Function f) const
        {
            return map(f).concat();
        }
        */

        
    private:

        template <typename T>
        class Node
        {
            public:
                Node() : next(NULL) {}
                Node(T v, Node<T>* n = NULL) : value(v), next(n) {}
                T value;
                Node<T>* next;
            
        };

        Node<A> *head;

        List(Node<A>* h)
        {
            head = h;
        }
        List(A val, Node<A>* n)
        {
            head = new Node<A>(val, n);
        }
    
};

#endif
