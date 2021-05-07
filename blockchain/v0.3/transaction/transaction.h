#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "blockchain.h"

/**
 * struct transaction_s - Transaction structure
 *
 * @id:      Transaction ID. A hash of all the inputs and outputs.
 *           Prevents further alteration of the transaction.
 * @inputs:  List of `tx_in_t *`. Transaction inputs
 * @outputs: List of `tx_out_t *`. Transaction outputs
 */
typedef struct transaction_s
{
	uint8_t		id[SHA256_DIGEST_LENGTH];
	llist_t		*inputs;
	llist_t		*outputs;
} transaction_t;

/**
 * struct tx_out_s - Transaction output
 *
 * @amount: Amount received
 * @pub:	Receiver's public address
 * @hash:	Hash of @amount and @pub. Serves as output ID
 */
typedef struct tx_out_s
{
	uint32_t	amount;
	uint8_t		pub[EC_PUB_LEN];
	uint8_t		hash[SHA256_DIGEST_LENGTH];
} tx_out_t;


tx_out_t *tx_out_create(uint32_t amount, uint8_t const pub[EC_PUB_LEN]);
#endif
