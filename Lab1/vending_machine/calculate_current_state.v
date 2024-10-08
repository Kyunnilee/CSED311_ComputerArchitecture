
`include "vending_machine_def.v"
	

module calculate_current_state(i_input_coin,i_select_item,item_price,coin_value,current_total,
current_total_nxt,wait_time,o_return_coin,o_available_item,o_output_item);


	
	input [`kNumCoins-1:0] i_input_coin,o_return_coin;
	input [`kNumItems-1:0]	i_select_item;			
	input [31:0] item_price [`kNumItems-1:0];
	input [31:0] coin_value [`kNumCoins-1:0];	
	input [`kTotalBits-1:0] current_total;
	input [31:0] wait_time;
	output reg [`kNumItems-1:0] o_available_item,o_output_item;
	output reg [`kTotalBits-1:0] current_total_nxt;
	integer i;	


	reg [`kTotalBits-1:0] input_total, output_total, return_total;
	reg [`kNumItems-1:0] output_item;
	
	// Combinational logic for the next states
	always @(*) begin
		// TODO: current_total_nxt
		// You don't have to worry about concurrent activations in each input vector (or array).
		// Calculate the next current_total state.
		
		// Initialize values
		input_total = 0;
		output_total = 0;
		return_total = 0;
		output_item = 0;

		// Calculate total input coin value
		for (i = 0; i < `kNumCoins; i++) begin
			if (i_input_coin[i]) begin
				input_total = input_total + coin_value[i];
			end
		end

		// Calculate total output coin value (for purchasing items)
		for (i = 0; i < `kNumItems; i++) begin 
			if (i_select_item[i] && ((current_total - output_total) >= item_price[i])) begin // if the selected item can be dispensed
				output_total = output_total + item_price[i];
				output_item[i] = 1;
			end
		end	

		// Calculate total return coin value
		for (i = 0; i < `kNumCoins; i++) begin 
			if (o_return_coin[i]) begin 
				return_total = return_total + coin_value[i];
			end
		end

		// Calculate next current_total state
		current_total_nxt = current_total + input_total - output_total - return_total;
	end
	
	// Combinational logic for the outputs
	always @(*) begin
		// TODO: o_available_item
		// TODO: o_output_item

		// Initialize values
		o_available_item = 0;
		o_output_item = 0;

		if (wait_time > 0) begin // if it's within the waiting time
			for (i = 0; i < `kNumItems; i++) begin
				if (current_total >= item_price[i]) begin // if the item is available
					o_available_item[i] = 1;
				end
			end

			for (i = 0; i < `kNumItems; i++) begin
				if (i_select_item[i] && output_item[i]) begin // if the item can be dispensed
					o_output_item[i] = 1;
				end
			end
		end 
	end

endmodule 
