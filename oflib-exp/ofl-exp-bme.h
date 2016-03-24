
#ifndef OFL_EXP_BME_H
#define OFL_EXP_BME_H 1


#include "../oflib/ofl-structs.h"
#include "openflow/openflow.h"

struct ofl_bme_action_header {
    struct ofl_action_header header;  /* OFPAT_EXPERIMENTER */
    uint32_t experimenter_id;         /* BME_EXPERIMENTER_ID */
    uint32_t type;
};

struct ofl_bme_set_metadata {
    struct ofl_action_header   header; /* OFPAT_EXPERIMENTER */
    uint32_t experimenter_id;          /* BME_EXPERIMENTER_ID */
    uint32_t type;                     /* BME_SET_METADATA_FROM_PACKET */
    uint32_t field;
    uint8_t offset;
};

struct ofl_bme_set_mpls_label {
    struct ofl_action_header   header; /* OFPAT_EXPERIMENTER */
    uint32_t experimenter_id;          /* BME_EXPERIMENTER_ID */
    uint32_t type;                     /* BME_SET_MPLS_LABEL_FROM_COUNTER */
};

struct ofl_bme_xor_packet {
    struct ofl_action_header   header; /* OFPAT_EXPERIMENTER */
    uint32_t experimenter_id;          /* BME_EXPERIMENTER_ID */
    uint32_t type;                     /* BME_XOR_* */
    uint32_t label_a;
    uint32_t label_b;
};

struct ofl_bme_update_distance {
    struct ofl_action_header   header; /* OFPAT_EXPERIMENTER */
    uint32_t experimenter_id;          /* BME_EXPERIMENTER_ID */
    uint32_t type;                     /* BME_SET_MPLS_LABEL_FROM_COUNTER */
    uint8_t  hw_addr[OFP_ETH_ALEN];    /* Ethernet address. */
    uint32_t port;                     /* Output port. 
					* NB: interpreted as uint16_t! */
};

struct ofl_bme_set_metadata_from_counter {
    struct ofl_action_header   header; /* OFPAT_EXPERIMENTER */
    uint32_t experimenter_id;          /* BME_EXPERIMENTER_ID */
    uint32_t type;                     /* BME_SET_METADATA_FROM_COUNTER */
    uint32_t max_num;
};

struct ofl_bme_serialize {
    struct ofl_action_header   header; /* OFPAT_EXPERIMENTER */
    uint32_t experimenter_id;          /* BME_EXPERIMENTER_ID */
    uint32_t type;                     /* BME_SERIALIZE */
    uint32_t mpls_label;
    uint16_t timeout;
};

/* see ofl.h */

int
ofl_exp_bme_act_pack(struct ofl_action_header *src,
		     struct ofp_action_header *dst);

ofl_err
ofl_exp_bme_act_unpack(struct ofp_action_header *src, size_t *len,
		       struct ofl_action_header **dst);

int
ofl_exp_bme_act_free(struct ofl_action_header *act);

size_t
ofl_exp_bme_act_ofp_len(struct ofl_action_header *act);

char*
ofl_exp_bme_act_to_string(struct ofl_action_header *act);

int
ofl_exp_bme_inst_pack(struct ofl_instruction_header *src,
		      struct ofp_instruction *dst);

ofl_err
ofl_exp_bme_inst_unpack(struct ofp_instruction *src, size_t *len,
			struct ofl_instruction_header **dst);

int
ofl_exp_bme_inst_free(struct ofl_instruction_header *i);

size_t
ofl_exp_bme_inst_ofp_len(struct ofl_instruction_header *i);

char*
ofl_exp_bme_inst_to_string(struct ofl_instruction_header *i);


#endif /* OFL_EXP_BME_H */
