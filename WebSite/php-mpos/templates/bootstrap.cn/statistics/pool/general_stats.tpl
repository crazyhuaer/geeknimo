  <div class="col-lg-6">
    <div class="panel panel-info">
      <div class="panel-heading">
        <i class="fa fa-bar-chart-o fa-fw"></i> 统计数据

      </div>
      <div class="panel-body no-padding table-responsive">
        <table class="table table-striped table-bordered table-hover">
          <tbody>
            <tr>
              <th width="50%">矿池速度</th>
              <td width="70%"><span id="b-hashrate">{$GLOBAL.hashrate|number_format:"3"}</span> {$GLOBAL.hashunits.pool}</td>
            </tr>
            <tr>
              <th>矿池效率</th>
              <td>{if $GLOBAL.roundshares.valid > 0}{($GLOBAL.roundshares.valid / ($GLOBAL.roundshares.valid + $GLOBAL.roundshares.invalid) * 100)|number_format:"2"}%{else}0%{/if}</td>
            </tr>
            <tr>
              <th>当前活动矿工</th>
              <td id="b-workers">{$GLOBAL.workers|number_format}</td>
            </tr>
            <tr>
              <th>当前难度</th>
              {if ! $GLOBAL.website.chaininfo.disabled}
              <td><a href="{$GLOBAL.website.chaininfo.url}" target="_new"><font size="2"><span id="b-diff">{$NETWORK.difficulty}</span></font></a></td>
              {else}
              <td><span id="b-diff">{$NETWORK.difficulty}</span></td>
              {/if}
            </tr>
            <tr>
              <th>预计下次难度</th>
              {if ! $GLOBAL.website.chaininfo.disabled}
              <td><a href="{$GLOBAL.website.chaininfo.url}" target="_new"><font size="2">{$NETWORK.EstNextDifficulty|number_format:"8"} (Change in {$NETWORK.BlocksUntilDiffChange} Blocks)</font></a></td>
              {else}
              <td><font size="2">{$NETWORK.EstNextDifficulty|number_format:"8"} (将在 {$NETWORK.BlocksUntilDiffChange} 个块后变化)</font></td>
              {/if}
            </tr>
            <tr>
              <th>预计每回合平均时间 (全网)</th>
              <td><font size="2">{$NETWORK.EstTimePerBlock|seconds_to_words}</font></td>
            </tr>
            <tr>
              <th>预计每回合平均时间 (矿池)</th>
              <td>{$ESTTIME|seconds_to_words}</td>
            </tr>
            <tr>
              <th>预计本轮股份</th>
              <td id="b-target">{$ESTIMATES.shares|number_format} (done: {$ESTIMATES.percent}%)</td>
            </tr>
            {if ! $GLOBAL.website.blockexplorer.disabled}
            <tr>
              <th width="50%">全网下一个区块</th>
              <td colspan="3">{($CURRENTBLOCK + 1)|number_format}   <font size="1"> (当前: <a href="{$GLOBAL.website.blockexplorer.url}{$CURRENTBLOCKHASH}" target="_new">{$CURRENTBLOCK|number_format})</a></font></td>
            </tr>
            {else}
            <tr>
              <th>全网下一个区块</th>
              <td colspan="3">{($CURRENTBLOCK + 1)|number_format}    (当前: {$CURRENTBLOCK|number_format})</td>
            </tr>
            {/if}
            <tr>
              <th>最近发现的区块</th>
              <td colspan="3"><a href="{$smarty.server.SCRIPT_NAME}?page=statistics&action=round&height={$LASTBLOCK}" target="_new">{$LASTBLOCK|default:"0"|number_format}</a></td>
            </tr>
            <tr>
              <th>距离上个区块的时间</th>
              <td colspan="3">{$TIMESINCELAST|seconds_to_words}</td>
            </tr>
          </tbody>
        </table>
      </div>
      <div class="panel-footer">
        <h6>{if !$GLOBAL.website.api.disabled}这些统计的 JSON 格式在 <a href="{$smarty.server.SCRIPT_NAME}?page=api&action=getpoolstatus&api_key={$GLOBAL.userdata.api_key|default:""}">这里</a>{/if}</h6>
      </div>
    </div>
  </div>
