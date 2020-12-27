/* Liste
					
Per una stazione di servizio per il rifornimento self-service di carburante, si vogliono 
implementare alcuni moduli del software C++ per la gestione delle pompe e della cassa. In 
particolare vi si chiede di sviluppare la funzione attivaPompa() che, ricevuti come parametri la 
lista dei rifornimenti in attesa di pagamento e la pompa che richiede l’abilitazione al 
rifornimento, restituisca tale abilitazione solo se nella lista di attesa è presente al più un 
rifornimento pendente per il pagamento relativamente alla stessa pompa. La funzione 
rifornimento(), ricevuti come parametri la lista dei rifornimenti già effettuati e non ancora 
pagati, il numero di pompa, il numero di litri erogati ed il prezzo unitario del carburante, dopo 
aver ricevuto il consenso dalla funzione attivaPompa(), dovrà erogare il carburante registrando 
in coda alla lista stessa il rifornimento, indicandone litri, numero di pompa ed importo. Infine vi 
si chiede di sviluppare la funzione cassa() che, ricevuti la lista dei rifornimenti erogati e non 
ancora pagati ed il numero di pompa, individui nella lista il primo rifornimento da regolarizzare 
presente per quella pompa, eliminandolo dalla lista stessa e stampando a video numero di 
pompa ed importo. */
				
			
		
