//
//  main.cpp
//  Attribute_Parser
//
//  Created by Dinaol Melak on 5/13/19.
//  Copyright © 2019 Dinaol Melak. All rights reserved.
//
//We have defined our own markup language HRML. In HRML, each element consists of a starting and ending tag, and there are attributes associated with each tag. Only starting tags can have attributes. We can call an attribute by referencing the tag, followed by a tilde, '~' and the name of the attribute. The tags may also be nested.
//
//The opening tags follow the format:
//
///<tag-name attribute1-name = "value1" attribute2-name = "value2" ...>
//
//The closing tags follow the format:
//
///</tag-name>
#include <cmath>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class attribute{
private:
    string attributeName;
    string value;
    attribute *nextAttrPtr;
public:
    attribute(){
        attributeName = "";
        value = "";
    }
    void setAttribute(string nameIn,string valueIn){
        attributeName = nameIn;
        value = valueIn;
    }
    void setAttributeName(string attrNameIn){
        this->attributeName = attrNameIn;
    }
    void setAttributeValue(string attrValueIn){
        this->value = attrValueIn;
    }
    string getAttributeName(){
        return this->attributeName;
    }
    string getAttributeValue(){
        return this->value;
    }
    void setNextAttrPtr(attribute* attrPtr){
        nextAttrPtr=attrPtr;
    }
    attribute* getNextAttrPtr(){
        return nextAttrPtr;
    }
    
    
};


class tag{
private:
    string tagName;
    attribute tagAttribute;
    attribute *headAttributePtr;
public:
    tag(){
        
        headAttributePtr = new attribute;
        headAttributePtr->setNextAttrPtr(0);
    }
    attribute *getHeadAttrPtr(){
        return headAttributePtr;
    }
    bool isEmpty(){
        if (headAttributePtr->getNextAttrPtr()==0){
            return true;
        }else{
            return false;
        }
    }
    void setTag(string tagStr){
///<tag-name attribute1-name = "value1" attribute2-name = "value2" ...>
        string myAttr,myTag,myValue;
        char mySwitchTrigger = 'Z';
        for(int i=0;i<tagStr.length();i++){
            switch (mySwitchTrigger){
                case 'A':
                    if(tagStr[i] == '='&& tagStr[i+1] == ' '){
                        
                    }else if(tagStr[i] == ' '&& tagStr[i+1]=='"'){
                        mySwitchTrigger = 'V';
                    }else if(tagStr[i]==' '&&tagStr[i+1]=='='){
                        
                    }
                    else{
                        myAttr += tagStr[i];
                    }
                    break;
                case 'T':
                    if(tagStr[i]==' '){
                        mySwitchTrigger = 'A';
                    }else{
                        myTag += tagStr[i];
                    }
                    break;
                case 'V':
                    if(tagStr[i] == '"' && tagStr[i+1] == ' '){
                        mySwitchTrigger = 'P';
                    }else if(tagStr[i] == '"' && tagStr[i+1] == '>'){
                        mySwitchTrigger = 'P';
                    }else if(tagStr[i-1]==' ' && tagStr[i]=='"'){
                        
                    }
                    else{
                        myValue += tagStr[i];
                    }
                    break;
                case 'P':
                    tagName = myTag;
                    addAttribute(myAttr, myValue);
                    myAttr="";
                    myValue="";
                    if(tagStr[i]=='>'){
                        break;
                    }else{
                        mySwitchTrigger = 'A';
                    }
                    break;
                
                default:
                    if(tagStr[i]=='<'){
                        mySwitchTrigger = 'T';
                    }else if (tagStr[i] == '>'){
                        
                    }
                    break;
                    
            }
        }
        
    }
    void printTag(){
        
        attribute *currentAttrPtr = headAttributePtr->getNextAttrPtr();
        cout<<tagName<<endl;
        while(currentAttrPtr!=0){
            cout<<currentAttrPtr->getAttributeName()<<":"<<currentAttrPtr->getAttributeValue()<<endl;
            currentAttrPtr = currentAttrPtr->getNextAttrPtr();
        }
        /*
        if (tagAttribute.getAttributeName()!=""&&tagAttribute.getAttributeValue()!=""&&(headAttributePtr==NULL)){
            cout<<tagName<<endl<<tagAttribute.getAttributeName()<<":"<<tagAttribute.getAttributeValue()<<endl;
            
        }else if(headAttributePtr!=NULL){
            attribute *nextAttrPtr = headAttributePtr;
            
            cout<<tagName<<endl<<tagAttribute.getAttributeName()<<":"<<tagAttribute.getAttributeValue()<<endl;
            while (nextAttrPtr!=NULL){
                
                cout<<"     "<<nextAttrPtr->getAttributeName()<<":"<<nextAttrPtr->getAttributeValue()<<endl;
                
                nextAttrPtr=nextAttrPtr->getNextAttrPtr();
            }
        }
        else{
            cout<< "Their is nothing to print!\n";
        }
        */
        
    }
    void addAttribute(string attrName, string attrValue){
        attribute *currentAttrPtr = headAttributePtr->getNextAttrPtr();
        attribute *prevAttrPtr = headAttributePtr;
        
        while (currentAttrPtr != 0){
            prevAttrPtr = currentAttrPtr;
            currentAttrPtr = currentAttrPtr->getNextAttrPtr();
        }
        attribute *newAttribute = new attribute;
        newAttribute->setAttributeName(attrName);
        newAttribute->setAttributeValue(attrValue);
        newAttribute->setNextAttrPtr(0);
        prevAttrPtr->setNextAttrPtr(newAttribute);
        /*
        if(this->tagAttribute.getAttributeName()=="" &&this->tagAttribute.getAttributeValue()==""){
            this->tagAttribute.setAttributeName(attrName);
            this->tagAttribute.setAttributeValue(attrValue);
            
            
           // prevAttrRef->setNextAttrPtr(newAttribute);
        }else{
            attribute *currentAttrRef =headAttributePtr;
            attribute *prevAttrRef = headAttributePtr;
            while(currentAttrRef!=NULL){
                prevAttrRef = currentAttrRef;
                currentAttrRef = currentAttrRef->getNextAttrPtr();
            }
            attribute *newAttribute = new attribute;
            newAttribute->setAttributeName(attrName);
            newAttribute->setAttributeValue(attrValue);
            prevAttrRef->setNextAttrPtr(newAttribute);
            
        }
         */
    }
};

int main() {
    string str;
    cout<<"str please!\n";
    getline(cin,str);
    tag testTag;
    testTag.setTag(str);
    testTag.printTag();
    
    
    /*
    string myTag,myAttr,myValue;
    char mySwitchTrigger = 'Z';
    for(int i=0;i<str.length();i++){
        switch (mySwitchTrigger){
            case 'A':
                if(str[i] == '='&& str[i+1] == ' '){
                    
                }else if(str[i] == ' '&& str[i+1]!='"'){
                    
                }else if(str[i] == ' '&& str[i+1]=='"'){
                    mySwitchTrigger = 'V';
                }
                else{
                    myAttr += str[i];
                }
                break;
            case 'T':
                if(str[i]==' '){
                    mySwitchTrigger = 'A';
                }else{
                    myTag += str[i];
                }
                break;
            case 'V':
                if(str[i] == '"' && str[i+1] != '>'){
                    //mySwitchTrigger = 'O';
                }else if(str[i] == '"' && str[i+1] == '>'){
                    mySwitchTrigger = 'Z';
                }else{
                    myValue += str[i];
                }
                break;
                //case 'O':
                
                //    break;
            default:
                if(str[i]=='<'){
                    mySwitchTrigger = 'T';
                }else if (str[i] == '>'){
                    
                }
                break;
                
        }
    }
    */
    
    
    
    return 0;
}


/*
 for(int i=0;i<str.length();i++){
 if(str[0]=='<'&&str[1]!='/'){
 if(str[i]!='<'&&str[i]!=' '){
 tag1+=str[i];
 }
 if(str[i]==' '){
 while(str[i+1]!='='){
 attr1+=str[i];
 }
 }else if(str[i]==' '&&str[i+1]=='"'){
 while(str[i+1]!='"'){
 value1+=str[i];
 }
 }
 }
 
 }
 */
