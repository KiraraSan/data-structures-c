#include "header.h"

AddressChild alokasiChild(DataChild data){
	AddressChild ac;
	
	ac = (AddressChild) malloc(sizeof(NodeChild));
	
	ac->next = NULL;
	ac->dataChild = data;
	
	return ac;
}

void insertFirstChild(Multilist l, AddressParent parent, DataChild data){
	
	AddressChild dataBaru = alokasiChild(data);
	dataBaru->next = parent->firstChild;
		
	parent->firstChild = dataBaru;
}

AddressChild findChild(Multilist l, AddressParent parent, int idPeriksa){
	
	AddressChild temp = parent->firstChild;
	
	while(temp != NULL){
		if(temp->dataChild.idPeriksa == idPeriksa){
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

void deleteAtChild(AddressParent parent, int idHewan){
	AddressChild temp = parent->firstChild;
	AddressChild hapus;
	
	if(temp->dataChild.idHewan == idHewan){
		parent->firstChild = temp->next;
		free(temp);
	}else{
		while(temp->next != NULL){
			if(temp->next->dataChild.idHewan == idHewan){
				break;
			}
			temp = temp->next;
		}
		hapus = temp->next;
		temp->next = hapus->next;
		free(hapus);
	}
	
}
