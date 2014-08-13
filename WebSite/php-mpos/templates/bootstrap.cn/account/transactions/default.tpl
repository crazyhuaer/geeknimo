<div class="row">
  <form class="col-lg-3" role="form">
    <input type="hidden" name="page" value="{$smarty.request.page|escape}">
    <input type="hidden" name="action" value="{$smarty.request.action|escape}">
    <input type="hidden" name="ctoken" value="{$CTOKEN|escape|default:""}" />
    <div class="panel panel-info">
      <div class="panel-heading">
        <i class="fa fa-search fa-fw"></i> 分币查询
      </div>
      <div class="panel-body">
            <ul class="pager">
              <li class="previous {if $smarty.get.start|default:"0" <= 0}disabled{/if}">
                <a href="{if $smarty.get.start|default:"0" <= 0}#{else}{$smarty.server.SCRIPT_NAME}?page={$smarty.request.page|escape}&action={$smarty.request.action|escape}&start={$smarty.request.start|escape|default:"0" - $LIMIT}{if $FILTERS|default:""}{$FILTERS}{/if}{/if}">← 上一个</a>
              </li>
              <li class="next">
                <a href="{$smarty.server.SCRIPT_NAME}?page={$smarty.request.page|escape}&action={$smarty.request.action|escape}&start={$smarty.request.start|escape|default:"0" + $LIMIT}{if $FILTERS|default:""}{$FILTERS}{/if}">下一个 →</a>
              </li>
            </ul>
            <div class="form-group">
              <label>类型</label>
              {html_options class="form-control select-mini" name="filter[type]" options=$TRANSACTIONTYPES selected=$smarty.request.filter.type|default:""}
            </div>
            <div class="form-group">
              <label>状态</label>
              {html_options class="form-control select-mini" name="filter[status]" options=$TXSTATUS selected=$smarty.request.filter.status|default:""}
            </div>
      </div>
      <div class="panel-footer">
        <input type="submit" value="确认" class="btn btn-success btn-sm">
      </div>
    </div>
  </form>

  <div class="col-lg-9">
    <div class="panel panel-info">
      <div class="panel-heading">
        <i class="fa fa-clock-o fa-fw"></i> 分币记录
      </div>
      <div class="panel-body no-padding">
        <div class="table-responsive">
          <table class="table table-striped table-bordered table-condensed">
            <thead>
              <tr>
                <th class="h6">ID</th>
                <th class="h6">时间</th>
                <th class="h6">TX 类型</th>
                <th class="h6">状态</th>
                <th class="h6">支付地址</th>
                <th class="h6">TX #</th>
                <th class="h6">区块 #</th>
                <th class="h6">数量</th>
              </tr>
            </thead>
            <tbody>
{section transaction $TRANSACTIONS}
              <tr>
                <td>{$TRANSACTIONS[transaction].id}</td>
                <td>{$TRANSACTIONS[transaction].timestamp}</td>
                <td>{$TRANSACTIONS[transaction].type}</td>
                <td>
                  {if $TRANSACTIONS[transaction].type == 'Credit_PPS' OR
                  $TRANSACTIONS[transaction].type == 'Fee_PPS' OR
                  $TRANSACTIONS[transaction].type == 'Donation_PPS' OR
                  $TRANSACTIONS[transaction].type == 'Debit_MP' OR
                  $TRANSACTIONS[transaction].type == 'Debit_AP' OR
                  $TRANSACTIONS[transaction].type == 'TXFee' OR
                  $TRANSACTIONS[transaction].confirmations >= $GLOBAL.confirmations
                  }
                  <span class="label label-success">Confirmed</span>
                  {else if $TRANSACTIONS[transaction].confirmations == -1}
                  <span class="label label-danger">Orphaned</span>
                  {else}
                  <span class="label label-warning">Unconfirmed</span>
                  {/if}
                </td>
                <td><a href="#" onClick="alert('{$TRANSACTIONS[transaction].coin_address|escape}')">{$TRANSACTIONS[transaction].coin_address|truncate:20:"...":true:true}</a></td>
                {if ! $GLOBAL.website.transactionexplorer.disabled}
                <td><a href="{$GLOBAL.website.transactionexplorer.url}{$TRANSACTIONS[transaction].txid|escape}" title="{$TRANSACTIONS[transaction].txid|escape}" target="_blank">{$TRANSACTIONS[transaction].txid|truncate:20:"...":true:true}</a></td>
                {else}
                <td><a href="#" onClick="alert('{$TRANSACTIONS[transaction].txid|escape}')" title="{$TRANSACTIONS[transaction].txid|escape}">{$TRANSACTIONS[transaction].txid|truncate:20:"...":true:true}</a></td>
                {/if}
                <td>{if $TRANSACTIONS[transaction].height == 0}n/a{else}<a href="{$smarty.server.SCRIPT_NAME}?page=statistics&action=round&height={$TRANSACTIONS[transaction].height}">{$TRANSACTIONS[transaction].height}</a>{/if}</td>
                <td><font color="{if $TRANSACTIONS[transaction].type == 'Credit' or $TRANSACTIONS[transaction].type == 'Credit_PPS' or $TRANSACTIONS[transaction].type == 'Bonus'}green{else}red{/if}">{$TRANSACTIONS[transaction].amount|number_format:"8"}</td>
              </tr>
{/section}
            </tbody>
          </table>
        </div>
      </div>
      <div class="panel-footer">
        <h6><b>Debit_AP</b> = 自动提币, <b>Debit_MP</b> = 手动提币, <b>Donation</b> = 捐赠, <b>Fee</b> = 矿池费用 (如果矿池收费)</h6>
        <h6><b>Confirmed</b> = 已确认, <b>Orphaned</b> = 孤儿, <b>Unconfirmed</b> = 未确认</h6>
      </div>
    </div>
  </div>
</div>
